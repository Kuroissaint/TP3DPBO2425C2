public class Sword extends Weapon {
    private double sharpness;
    private double attackSpeed;
    private double blockChance;

    public Sword(String name, int level, String tier, WeaponMaterial material, 
                 double sharpness, double attackSpeed, double blockChance) {
        super(name, level, tier, material);
        this.sharpness = sharpness;
        this.attackSpeed = attackSpeed;
        this.blockChance = blockChance;
    }

    @Override
    protected String specificsInfo() {
        return "Sharpness: " + sharpness + ", Attack Speed: " + attackSpeed + ", Block Chance: " + blockChance;
    }

    // Getter untuk kebutuhan Hybrid
    public double getSharpness() { return sharpness; }
    public double getAttackSpeed() { return attackSpeed; }
    public double getBlockChance() { return blockChance; }
}