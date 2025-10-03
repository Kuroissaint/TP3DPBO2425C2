public class WeaponMaterial {
    private String rarity;
    private String quality;

    public WeaponMaterial(String rarity, String quality) {
        this.rarity = rarity;
        this.quality = quality;
    }

    public void displayMaterial() {
        System.out.println("  [MATERIAL] Rarity: " + rarity + ", Quality: " + quality);
    }
}