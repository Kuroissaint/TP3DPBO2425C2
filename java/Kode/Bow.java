public class Bow extends Weapon {
    private int arrows;
    private double range;
    private double drawSpeed;

    public Bow(String name, int level, String tier, WeaponMaterial material, 
               int arrows, double range, double drawSpeed) {
        // Panggilan ke constructor Base Class (Weapon)
        super(name, level, tier, material);
        this.arrows = arrows;
        this.range = range;
        this.drawSpeed = drawSpeed;
    }

    @Override
    protected String specificsInfo() {
        return "Arrows: " + arrows + ", Range: " + range + ", Draw Speed: " + drawSpeed;
    }

    // Getter untuk kebutuhan Hybrid (Simulasi Multiple Inheritance)
    public int getArrows() { return arrows; }
    public double getRange() { return range; }
    public double getDrawSpeed() { return drawSpeed; }
}