#include <iostream>
#include <vector>
#include <memory>
#include <limits>
#include <utility>
#include <algorithm>
#include <iomanip>
#include <string> // Pastikan <string> di-include untuk getline()

// Include SEMUA file header yang dibutuhkan
#include "Character.h"
#include "Bow.h"
#include "Sword.h"
#include "Staff.h"
#include "HybridWeapon.h" 
#include "WeaponMaterial.h" 
#include "Type.h"
#include "Skill.h"

using namespace std;

// ===============================================
// DATA GLOBAL (Menyimpan semua data yang dibuat user)
// ===============================================
vector<unique_ptr<Character>> characters;
vector<unique_ptr<Weapon>> weapons;
vector<unique_ptr<Skill>> skills;
vector<unique_ptr<Type>> types;
vector<unique_ptr<WeaponMaterial>> materials;

// ===============================================
// FUNGSI UTILITY
// ===============================================

void clearBuffer() {
    if (cin.peek() != EOF)
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Fungsi untuk menampilkan dan memilih Weapon
Weapon* chooseWeapon() {
    if (weapons.empty()) {
        cout << "\nBelum ada Weapon yang terdaftar. Karakter tidak bisa di-equip." << endl;
        return nullptr;
    }
    
    cout << "\n--- Pilih Weapon yang Tersedia ---" << endl;
    for (size_t i = 0; i < weapons.size(); ++i) {
        cout << i + 1 << ". " << weapons[i]->Name << " (Lvl " << weapons[i]->Level << ")" << endl;
    }
    
    int choice;
    cout << "Pilih nomor Weapon (atau 0 untuk tidak equip): ";
    if (!(cin >> choice) || choice < 0 || choice > (int)weapons.size()) {
        cout << "Pilihan tidak valid. Tidak ada Weapon yang di-equip." << endl;
        cin.clear(); clearBuffer(); return nullptr;
    }
    
    if (choice == 0) return nullptr;
    
    return weapons[choice - 1].get();
}

// Fungsi untuk menampilkan dan memilih Skill
Skill* chooseSkill() {
    if (skills.empty()) {
        cout << "\nBelum ada Skill yang terdaftar. Karakter tidak bisa mempelajari Skill." << endl;
        return nullptr;
    }
    
    cout << "\n--- Pilih Skill yang Tersedia ---" << endl;
    for (size_t i = 0; i < skills.size(); ++i) {
        cout << i + 1 << ". " << skills[i]->Name << endl;
    }
    
    int choice;
    cout << "Pilih nomor Skill (atau 0 untuk tidak belajar): ";
    if (!(cin >> choice) || choice < 0 || choice > (int)skills.size()) {
        cout << "Pilihan tidak valid. Tidak ada Skill yang dipelajari." << endl;
        cin.clear(); clearBuffer(); return nullptr;
    }
    
    if (choice == 0) return nullptr;
    
    return skills[choice - 1].get();
}


// Fungsi untuk membuat objek Type baru dari 3 pilihan user (Damage/Attack/Scaling)
Type* selectAndCombineType() {
    string dmg, atk, scl;
    int choice;
    
    cout << "\n--- Membentuk Tipe Baru ---" << endl;

    // --- Pilihan 1: Damage Type (Physical / Magical) ---
    cout << "\n--- Pilih Damage Type ---" << endl;
    cout << "1. Physical" << endl;
    cout << "2. Magical" << endl;
    cout << "Pilihan: ";
    if (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Pilihan tidak valid. Membatalkan input Type." << endl;
        cin.clear(); clearBuffer(); return nullptr;
    }
    dmg = (choice == 1) ? "Physical" : "Magical";
    
    // --- Pilihan 2: Attack Type (Melee / Range) ---
    cout << "\n--- Pilih Attack Type ---" << endl;
    cout << "1. Melee" << endl;
    cout << "2. Range" << endl;
    cout << "Pilihan: ";
    if (!(cin >> choice) || (choice != 1 && choice != 2)) {
        cout << "Pilihan tidak valid. Membatalkan input Type." << endl;
        cin.clear(); clearBuffer(); return nullptr;
    }
    atk = (choice == 1) ? "Melee" : "Range";
    
    // --- Pilihan 3: Scaling (STR / INT / DEX) ---
    cout << "\n--- Pilih Scaling Stat ---" << endl;
    cout << "1. STR (Strength)" << endl;
    cout << "2. INT (Intelligence)" << endl;
    cout << "3. DEX (Dexterity)" << endl;
    cout << "Pilihan: ";
    if (!(cin >> choice) || choice < 1 || choice > 3) {
        cout << "Pilihan tidak valid. Membatalkan input Type." << endl;
        cin.clear(); clearBuffer(); return nullptr;
    }
    if (choice == 1) scl = "STR";
    else if (choice == 2) scl = "INT";
    else scl = "DEX";
    
    // Buat objek Type baru, simpan di vektor global, dan kembalikan pointer
    types.push_back(make_unique<Type>(dmg, atk, scl));
    
    return types.back().get();
}

// ===============================================
// FUNGSI TAMBAH DATA (COMMANDS 4, 5, 6)
// ===============================================

void addCharacter() {
    string u, j;
    int l, hp, m;
    
    cout << "\n--- Tambah Data Character ---" << endl;
    cout << "Username: "; clearBuffer(); getline(cin, u);
    cout << "Job: "; getline(cin, j);
    cout << "Level: "; cin >> l;
    cout << "HP: "; cin >> hp;
    cout << "Mana: "; cin >> m;
    
    // 1. Buat Karakter Baru
    characters.push_back(make_unique<Character>(u, l, j, hp, m));
    Character* newChar = characters.back().get();
    
    // 2. Pilih dan Equip Weapon (Asosiasi)
    cout << "\n--- Pemilihan Weapon ---" << endl;
    Weapon* selectedWeapon = chooseWeapon();
    if (selectedWeapon) {
        newChar->equipWeapon(selectedWeapon);
        cout << "Weapon " << selectedWeapon->Name << " di-equip." << endl;
    } else {
        cout << "Karakter dibuat tanpa Weapon." << endl;
    }

    // 3. Pilih dan Equip Skill (Asosiasi)
    cout << "\n--- Pemilihan Skill ---" << endl;
    Skill* selectedSkill = chooseSkill();
    if (selectedSkill) {
        newChar->learnSkill(selectedSkill);
        cout << "Skill " << selectedSkill->Name << " dipelajari." << endl;
    } else {
        cout << "Karakter dibuat tanpa Skill." << endl;
    }

    cout << "\nKarakter '" << u << "' berhasil dibuat." << endl;
}

void addWeapon() {
    string n, wType;
    int l;
    
    cout << "\n--- Tambah Data Weapon ---" << endl;
    
    // 1. Pilih dan Kombinasikan Tipe
    Type* selectedType = selectAndCombineType();
    if (!selectedType) return;
    
    // 2. Input Dasar
    cout << "\nJenis Weapon (Bow/Sword/Staff/Hybrid/Other): "; clearBuffer(); getline(cin, wType);
    transform(wType.begin(), wType.end(), wType.begin(), ::tolower);

    cout << "Nama Weapon: "; getline(cin, n);
    cout << "Level: "; cin >> l;
    
    // 3. Input Material (Komposisi)
    string mtR, mtQ;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Material Rarity: "; getline(cin, mtR);
    cout << "Material Quality: "; getline(cin, mtQ);
    auto mat = make_unique<WeaponMaterial>(mtR, mtQ);

    // 4. Buat Weapon Spesifik
    string weaponTier = selectedType->DamageType; 

    if (wType == "bow") {
        int arr; double rng, ds;
        cout << "Arrows: "; cin >> arr;
        cout << "Range: "; cin >> rng;
        cout << "Draw Speed: "; cin >> ds;
        weapons.push_back(make_unique<Bow>(n, l, weaponTier, vector<pair<string, double>>{}, std::move(mat), arr, rng, ds));
    } 
    else if (wType == "sword") {
        double sh, as, bc;
        cout << "Sharpness: "; cin >> sh;
        cout << "Attack Speed: "; cin >> as;
        cout << "Block Chance: "; cin >> bc;
        weapons.push_back(make_unique<Sword>(n, l, weaponTier, vector<pair<string, double>>{}, std::move(mat), sh, as, bc));
    }
    else if (wType == "staff") {
        double ss; string e;
        cout << "Spelling Speed: "; cin >> ss;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Element: "; getline(cin, e);
        weapons.push_back(make_unique<Staff>(n, l, weaponTier, vector<pair<string, double>>{}, std::move(mat), ss, e));
    }
    // Implementasi Hybrid Weapon yang Direvisi
    else if (wType == "hybrid") {
        // Variabel untuk menyimpan data semua komponen
        int arr = 0; double rng = 0.0, bow_ds = 0.0;
        double swd_sh = 0.0, swd_as = 0.0, swd_bc = 0.0;
        double stf_ss = 0.0; string stf_e = "None";
        string cf, eff;

        // --- Tanyakan Komponen ---
        cout << "\n--- PILIH KOMPONEN HYBRID ---" << endl;
        cout << "Pilih komponen pertama (Bow/Sword/Staff): "; 
        string comp1; getline(cin, comp1);
        transform(comp1.begin(), comp1.end(), comp1.begin(), ::tolower);
        
        cout << "Pilih komponen kedua (Bow/Sword/Staff, berbeda dari yang pertama): "; 
        string comp2; getline(cin, comp2);
        transform(comp2.begin(), comp2.end(), comp2.begin(), ::tolower);

        // Kumpulkan data sesuai komponen yang dipilih
        // Pastikan untuk menghapus buffer jika input sebelumnya adalah numerik
        if (comp1 == "bow" || comp2 == "bow") {
            cout << "\n-- Input Data Bow --" << endl;
            cout << "Arrows: "; cin >> arr;
            cout << "Range: "; cin >> rng;
            cout << "Draw Speed: "; cin >> bow_ds;
        }
        if (comp1 == "sword" || comp2 == "sword") {
            cout << "\n-- Input Data Sword --" << endl;
            cout << "Sharpness: "; cin >> swd_sh;
            cout << "Attack Speed: "; cin >> swd_as;
            cout << "Block Chance: "; cin >> swd_bc;
        }
        if (comp1 == "staff" || comp2 == "staff") {
            cout << "\n-- Input Data Staff --" << endl;
            cout << "Spelling Speed: "; cin >> stf_ss;
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Bersihkan buffer setelah input numerik (jika ada)
            cout << "Element: "; getline(cin, stf_e);
        }
        
        // Data Hybrid Tambahan
        cf = comp1 + " & " + comp2; // Gabungkan nama komponen untuk CombinedFrom
        
        // Pastikan buffer bersih sebelum getline berikutnya
        if (comp1 != "staff" && comp2 != "staff") {
             cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }

        cout << "\n-- Data Hybrid --" << endl;
        cout << "Effect: "; 
        getline(cin, eff);

        weapons.push_back(make_unique<HybridWeapon>(
            n, l, weaponTier, vector<pair<string, double>>{}, std::move(mat), 
            arr, rng, bow_ds, // Bow data 
            swd_sh, swd_as, swd_bc, // Sword data
            stf_ss, stf_e, // Staff data
            cf, eff, selectedType
        ));
    }
    // Default Weapon
    else {
        weapons.push_back(make_unique<Weapon>(n, l, weaponTier, vector<pair<string, double>>{}, std::move(mat)));
    }
    
    cout << "Weapon '" << n << "' berhasil ditambahkan." << endl;
}

void addSkill() {
    string n;
    int mc; double cd;
    cout << "\n--- Tambah Data Skill ---" << endl;
    
    // 1. Pilih dan Kombinasikan Tipe
    Type* selectedType = selectAndCombineType();
    if (!selectedType) return;

    // 2. Input Dasar
    cout << "\nNama Skill: "; clearBuffer(); getline(cin, n);
    cout << "Mana Cost: "; cin >> mc;
    cout << "Cooldown: "; cin >> cd;
    
    skills.push_back(make_unique<Skill>(n, mc, cd, selectedType));
    cout << "Skill '" << n << "' berhasil ditambahkan." << endl;
}

// ===============================================
// FUNGSI DISPLAY (COMMANDS 1, 2, 3)
// ===============================================

void displayAllCharacters() {
    cout << "\n================= [ SEMUA CHARACTER ] =================" << endl;
    if (characters.empty()) {
        cout << "Belum ada Character yang terdaftar." << endl;
        return;
    }
    int i = 0;
    for (const auto& c : characters) {
        cout << "\n--- CHARACTER #" << ++i << " ---" << endl;
        c->displayCharacter(); 
    }
    cout << "\n========================================================" << endl;
}

void displayAllWeapons() {
    cout << "\n=================== [ SEMUA WEAPON ] ===================" << endl;
    if (weapons.empty()) {
        cout << "Belum ada Weapon yang terdaftar." << endl;
        return;
    }
    int i = 0;
    for (const auto& w : weapons) {
        cout << "\n--- WEAPON #" << ++i << " ---" << endl;
        w->displayWeapon(); // Panggil fungsi Polymorphic (LENGKAP)
    }
    cout << "\n========================================================" << endl;
}

void displayAllSkills() {
    cout << "\n==================== [ SEMUA SKILL ] ====================" << endl;
    if (skills.empty()) {
        cout << "Belum ada Skill yang terdaftar." << endl;
        return;
    }
    int i = 0;
    for (const auto& s : skills) {
        cout << "\n--- SKILL #" << ++i << " ---" << endl;
        s->displaySkillDetails(); 
    }
    cout << "\n=========================================================" << endl;
}


// ===============================================
// FUNGSI UTAMA (MAIN)
// ===============================================

int main() {
    
    int choice;
    do {
        cout << "\n\n=============== MENU APLIKASI RPG ================" << endl;
        cout << "1. Tampilkan Character" << endl;
        cout << "2. Tampilkan Weapon" << endl;
        cout << "3. Tampilkan Skill" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "4. Tambah Data Character" << endl;
        cout << "5. Tambah Data Weapon" << endl;
        cout << "6. Tambah Data Skill" << endl;
        cout << "------------------------------------------------" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilih Perintah: ";
        
        if (!(cin >> choice)) {
            cout << "Input tidak valid. Silakan masukkan angka." << endl;
            cin.clear();
            clearBuffer();
            choice = -1; 
            continue;
        }

        switch (choice) {
            case 1: displayAllCharacters(); break;
            case 2: displayAllWeapons(); break;
            case 3: displayAllSkills(); break;
            case 4: addCharacter(); break;
            case 5: addWeapon(); break;
            case 6: addSkill(); break;
            case 0: cout << "Terima kasih. Program berakhir." << endl; break;
            default: cout << "Pilihan tidak ada. Silakan coba lagi." << endl;
        }
    } while (choice != 0);

    return 0;
}