public class HybridWeapon extends Weapon {
    // Properti dari Bow
    private int arrows;
    private double range;
    private double drawSpeed;

    // Properti dari Sword
    private double sharpness;
    private double attackSpeed;
    private double blockChance;

    // Properti dari Staff
    private double spellingSpeed;
    private String element;

    // Properti Hybrid tambahan
    private String combinedFrom;
    private String effect;
    private Type specialType; // Association to Type

    // Constructor menerima semua properti gabungan
    public HybridWeapon(String name, int level, String tier, WeaponMaterial material, 
                        int arr, double rng, double bowDS, 
                        double swdSh, double swdAS, double swdBC, 
                        double stfSS, String stfE, 
                        String combinedFrom, String effect, Type specialType) {
        super(name, level, tier, material);
        
        // Inisialisasi atribut gabungan
        this.arrows = arr;
        this.range = rng;
        this.drawSpeed = bowDS;
        this.sharpness = swdSh;
        this.attackSpeed = swdAS;
        this.blockChance = swdBC;
        this.spellingSpeed = stfSS;
        this.element = stfE;
        
        // Atribut Hybrid
        this.combinedFrom = combinedFrom;
        this.effect = effect;
        this.specialType = specialType;
    }

    @Override
    protected String specificsInfo() {
        StringBuilder sb = new StringBuilder();
        sb.append("\n  --- HYBRID (Simulasi Multiple Inheritance) ---");

        // Info Bow
        if (arrows > 0 || range > 0 || drawSpeed > 0) {
            sb.append("\n    [BOW] Arrows: ").append(arrows)
              .append(", Range: ").append(range)
              .append(", Draw Speed: ").append(drawSpeed);
        }
        
        // Info Sword
        if (sharpness > 0 || attackSpeed > 0 || blockChance > 0) {
            sb.append("\n    [SWORD] Sharpness: ").append(sharpness)
              .append(", Attack Speed: ").append(attackSpeed)
              .append(", Block Chance: ").append(blockChance);
        }
            
        // Info Staff
        if (spellingSpeed > 0 || !element.equals("None")) {
            sb.append("\n    [STAFF] Element: ").append(element)
              .append(", Spelling Speed: ").append(spellingSpeed);
        }

        sb.append("\n  [HYBRID] Combined From: ").append(combinedFrom).append(", Effect: ").append(effect);
        
        if (specialType != null) {
            sb.append("\n  [TYPE] Special Type: ");
            specialType.displayType(); 
            sb.append("\n"); // Tambahkan baris baru setelah displayType
        }
        
        return sb.toString();
    }
}