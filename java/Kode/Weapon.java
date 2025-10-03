import java.util.UUID;

// Kelas dibuat Abstract karena Weapon dasar tidak seharusnya diinstansiasi
public abstract class Weapon {
    private String name;
    private int level;
    private String tier;
    private WeaponMaterial material; // Composition
    private UUID id;

    public Weapon(String name, int level, String tier, WeaponMaterial material) {
        this.name = name;
        this.level = level;
        this.tier = tier;
        this.material = material; // Composition
        this.id = UUID.randomUUID();
    }
    
    public String getName() {
        return name;
    }

    public int getLevel() {
        return level;
    }

    // Method abstract yang wajib di-implementasi (override) oleh Subclass
    protected abstract String specificsInfo();

    // Method polimorfik utama
    public void displayWeaponDetails(boolean fullDetail) {
        System.out.println("  [WEAPON] Name: " + name + " (Lvl " + level + ", Tier: " + tier + ")");
        
        if (fullDetail && material != null) {
            System.out.println("  --- Material (Composition) ---");
            material.displayMaterial();
        }
        
        String info = specificsInfo();
        if (info != null && !info.isEmpty()) {
            System.out.println("  Specifics: " + info);
        }
    }
}