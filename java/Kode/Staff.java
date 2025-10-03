public class Staff extends Weapon {
    private double spellingSpeed;
    private String element;

    public Staff(String name, int level, String tier, WeaponMaterial material, 
                 double spellingSpeed, String element) {
        super(name, level, tier, material);
        this.spellingSpeed = spellingSpeed;
        this.element = element;
    }

    @Override
    protected String specificsInfo() {
        return "Element: " + element + ", Spelling Speed: " + spellingSpeed;
    }

    // Getter untuk kebutuhan Hybrid
    public double getSpellingSpeed() { return spellingSpeed; }
    public String getElement() { return element; }
}