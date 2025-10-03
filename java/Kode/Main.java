import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.InputMismatchException;

public class Main {
    // GLOBAL STATE (Penyimpanan Data)
    private static List<Character> characters = new ArrayList<>();
    private static List<Weapon> weapons = new ArrayList<>();
    private static List<Skill> skills = new ArrayList<>();
    private static List<Type> types = new ArrayList<>(); // Menyimpan Type yang sudah dibuat
    private static Scanner scanner = new Scanner(System.in);

    // ===============================================
    // FUNGSI UTILITY INPUT
    // ===============================================

    private static String getStringInput(String prompt) {
        System.out.print(prompt);
        return scanner.nextLine();
    }

    private static int getIntInput(String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                int value = scanner.nextInt();
                scanner.nextLine(); // consume newline
                return value;
            } catch (InputMismatchException e) {
                System.out.println("Input tidak valid. Silakan masukkan angka bulat.");
                scanner.nextLine(); // clear buffer
            }
        }
    }

    private static double getDoubleInput(String prompt) {
        while (true) {
            try {
                System.out.print(prompt);
                double value = scanner.nextDouble();
                scanner.nextLine(); // consume newline
                return value;
            } catch (InputMismatchException e) {
                System.out.println("Input tidak valid. Silakan masukkan angka desimal.");
                scanner.nextLine(); // clear buffer
            }
        }
    }

    private static <T> T chooseItem(List<T> itemList, String itemName) {
        if (itemList.isEmpty()) {
            System.out.println("\n❌ Belum ada " + itemName + " yang terdaftar.");
            return null;
        }
        
        System.out.println("\n--- Pilih " + itemName + " yang Tersedia ---");
        for (int i = 0; i < itemList.size(); i++) {
            if (itemName.equals("Weapon")) {
                Weapon w = (Weapon) itemList.get(i);
                System.out.println((i + 1) + ". " + w.getName() + " (Lvl " + w.getLevel() + ")");
            } else {
                System.out.println((i + 1) + ". " + ((Skill) itemList.get(i)).getName());
            }
        }
        
        int choice = getIntInput("Pilih nomor " + itemName + " (atau 0 untuk tidak pilih): ");
        
        if (choice < 1 || choice > itemList.size()) {
            return null;
        }
        
        return itemList.get(choice - 1);
    }

    private static Type selectAndCombineType() {
        System.out.println("\n--- Membentuk Tipe Baru ---");

        // Damage Type
        System.out.println("\n--- Pilih Damage Type ---");
        System.out.println("1. Physical");
        System.out.println("2. Magical");
        String dmg = getIntInput("Pilihan (1/2): ") == 1 ? "Physical" : "Magical";

        // Attack Type
        System.out.println("\n--- Pilih Attack Type ---");
        System.out.println("1. Melee");
        System.out.println("2. Range");
        String atk = getIntInput("Pilihan (1/2): ") == 1 ? "Melee" : "Range";
        
        // Scaling
        System.out.println("\n--- Pilih Scaling Stat ---");
        System.out.println("1. STR");
        System.out.println("2. INT");
        System.out.println("3. DEX");
        int sclChoice = getIntInput("Pilihan (1/3): ");
        String scl;
        switch (sclChoice) {
            case 1: scl = "STR"; break;
            case 2: scl = "INT"; break;
            case 3: scl = "DEX"; break;
            default: scl = "N/A"; break;
        }
        
        Type newType = new Type(dmg, atk, scl);
        types.add(newType);
        return newType;
    }

    // ===============================================
    // FUNGSI TAMBAH DATA (COMMANDS 4, 5, 6)
    // ===============================================
    
    private static void addCharacter() {
        System.out.println("\n--- Tambah Data Character ---");
        String u = getStringInput("Username: ");
        String j = getStringInput("Job: ");
        int l = getIntInput("Level: ");
        int hp = getIntInput("HP: ");
        int m = getIntInput("Mana: ");
        
        Character newChar = new Character(u, l, j, hp, m);
        
        System.out.println("\n--- Pemilihan Weapon ---");
        Weapon selectedWeapon = chooseItem(weapons, "Weapon");
        if (selectedWeapon != null) {
            newChar.equipWeapon(selectedWeapon);
            System.out.println("✅ Weapon " + selectedWeapon.getName() + " di-equip.");
        }
        
        System.out.println("\n--- Pemilihan Skill ---");
        Skill selectedSkill = chooseItem(skills, "Skill");
        if (selectedSkill != null) {
            newChar.learnSkill(selectedSkill);
            System.out.println("✅ Skill " + selectedSkill.getName() + " dipelajari.");
        }

        characters.add(newChar);
        System.out.println("\n✅ Karakter '" + u + "' berhasil dibuat.");
    }

    private static void addWeapon() {
        System.out.println("\n--- Tambah Data Weapon ---");
        
        Type selectedType = selectAndCombineType();
        if (selectedType == null) return;

        String wType = getStringInput("\nJenis Weapon (Bow/Sword/Staff/Hybrid/Other): ").toLowerCase();
        String n = getStringInput("Nama Weapon: ");
        int l = getIntInput("Level: ");
        String weaponTier = selectedType.getDamageType();
        
        // Material (Composition)
        String mtR = getStringInput("Material Rarity: ");
        String mtQ = getStringInput("Material Quality: ");
        WeaponMaterial mat = new WeaponMaterial(mtR, mtQ);

        if (wType.equals("bow")) {
            int arr = getIntInput("Arrows: ");
            double rng = getDoubleInput("Range: ");
            double ds = getDoubleInput("Draw Speed: ");
            weapons.add(new Bow(n, l, weaponTier, mat, arr, rng, ds));
            
        } else if (wType.equals("sword")) {
            double sh = getDoubleInput("Sharpness: ");
            double ass = getDoubleInput("Attack Speed: ");
            double bc = getDoubleInput("Block Chance: ");
            weapons.add(new Sword(n, l, weaponTier, mat, sh, ass, bc));
            
        } else if (wType.equals("staff")) {
            double ss = getDoubleInput("Spelling Speed: ");
            String e = getStringInput("Element: ");
            weapons.add(new Staff(n, l, weaponTier, mat, ss, e));
            
        } else if (wType.equals("hybrid")) {
            // Data placeholder (default)
            int arr = 0; double rng = 0.0; double bowDS = 0.0;
            double swdSh = 0.0; double swdAS = 0.0; double swdBC = 0.0;
            double stfSS = 0.0; String stfE = "None";
            
            // --- Tanyakan Komponen ---
            System.out.println("\n--- PILIH KOMPONEN HYBRID (Maksimal 2 dari Bow/Sword/Staff) ---");
            String comp1 = getStringInput("Pilih komponen pertama (Bow/Sword/Staff): ").toLowerCase();
            String comp2 = getStringInput("Pilih komponen kedua (Bow/Sword/Staff): ").toLowerCase();
            
            if (comp1.equals("bow") || comp2.equals("bow")) {
                System.out.println("\n-- Input Data Bow --");
                arr = getIntInput("Arrows: ");
                rng = getDoubleInput("Range: ");
                bowDS = getDoubleInput("Draw Speed: ");
            }
            
            if (comp1.equals("sword") || comp2.equals("sword")) {
                System.out.println("\n-- Input Data Sword --");
                swdSh = getDoubleInput("Sharpness: ");
                swdAS = getDoubleInput("Attack Speed: ");
                swdBC = getDoubleInput("Block Chance: ");
            }
                
            if (comp1.equals("staff") || comp2.equals("staff")) {
                System.out.println("\n-- Input Data Staff --");
                stfSS = getDoubleInput("Spelling Speed: ");
                stfE = getStringInput("Element: ");
            }
            
            // Data Hybrid Tambahan
            String cf = comp1.substring(0, 1).toUpperCase() + comp1.substring(1) + " & " + 
                        comp2.substring(0, 1).toUpperCase() + comp2.substring(1);
            String eff = getStringInput("\nEffect Hybrid: ");

            weapons.add(new HybridWeapon(
                n, l, weaponTier, mat, 
                arr, rng, bowDS, 
                swdSh, swdAS, swdBC, 
                stfSS, stfE, 
                cf, eff, selectedType
            ));
            
        } else {
            // Default Weapon
            // weapons.add(new Weapon(n, l, weaponTier, mat)); 
            // Tidak bisa, karena Weapon dibuat Abstract di Java
            System.out.println("❌ Tipe weapon tidak dikenal. Mohon gunakan tipe yang tersedia.");
            return; 
        }
        
        System.out.println("✅ Weapon '" + n + "' berhasil ditambahkan.");
    }

    private static void addSkill() {
        System.out.println("\n--- Tambah Data Skill ---");
        
        Type selectedType = selectAndCombineType();
        if (selectedType == null) return;

        String n = getStringInput("\nNama Skill: ");
        int mc = getIntInput("Mana Cost: ");
        double cd = getDoubleInput("Cooldown: ");
        
        skills.add(new Skill(n, mc, cd, selectedType));
        System.out.println("✅ Skill '" + n + "' berhasil ditambahkan.");
    }

    // ===============================================
    // FUNGSI DISPLAY (COMMANDS 1, 2, 3)
    // ===============================================

    private static <T> void displayAll(List<T> itemList, String title, DisplayAction<T> action) {
        System.out.println("\n================= [ SEMUA " + title.toUpperCase() + " ] =================");
        if (itemList.isEmpty()) {
            System.out.println("❌ Belum ada " + title + " yang terdaftar.");
            return;
        }
        
        for (int i = 0; i < itemList.size(); i++) {
            System.out.println("\n--- " + title.toUpperCase() + " #" + (i + 1) + " ---");
            action.display(itemList.get(i));
        }
        System.out.println("\n========================================================");
    }

    // Functional Interface untuk display (Simulasi Lambda/Function di Python)
    @FunctionalInterface
    interface DisplayAction<T> {
        void display(T item);
    }

    // ===============================================
    // MAIN MENU
    // ===============================================

    public static void main(String[] args) {
        System.out.println("Selamat datang di Program Demonstrasi Konsep OOP (Java) dengan Modularisasi\n");
        
        while (true) {
            System.out.println("\n\n=============== MENU APLIKASI RPG ================");
            System.out.println("1. Tampilkan Character");
            System.out.println("2. Tampilkan Weapon");
            System.out.println("3. Tampilkan Skill");
            System.out.println("------------------------------------------------");
            System.out.println("4. Tambah Data Character (Pilih Weapon & Skill)");
            System.out.println("5. Tambah Data Weapon (Bentuk Type & Pilih Subclass)");
            System.out.println("6. Tambah Data Skill (Bentuk Type)");
            System.out.println("------------------------------------------------");
            System.out.println("0. Keluar");
            
            int choice = getIntInput("Pilih Perintah: ");
            
            switch (choice) {
                case 1: 
                    displayAll(characters, "Character", (c) -> ((Character)c).displayCharacter());
                    break;
                case 2: 
                    // Polymorphism: displayWeaponDetails dengan fullDetail=true
                    displayAll(weapons, "Weapon", (w) -> ((Weapon)w).displayWeaponDetails(true));
                    break;
                case 3: 
                    displayAll(skills, "Skill", (s) -> ((Skill)s).displaySkillDetails());
                    break;
                case 4: 
                    addCharacter();
                    break;
                case 5: 
                    addWeapon();
                    break;
                case 6: 
                    addSkill();
                    break;
                case 0:
                    System.out.println("Terima kasih. Program berakhir.");
                    scanner.close(); // Tutup scanner
                    return; // Keluar dari main method
                default:
                    System.out.println("Pilihan tidak ada. Silakan coba lagi.");
            }
        }
    }
}