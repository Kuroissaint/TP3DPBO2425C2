public class Type {
    private String damageType;
    private String attackType;
    private String scaling;

    public Type(String damageType, String attackType, String scaling) {
        this.damageType = damageType;
        this.attackType = attackType;
        this.scaling = scaling;
    }

    public String getDamageType() {
        return damageType;
    }

    public void displayType() {
        System.out.print("[TYPE] Damage: " + damageType + ", Attack: " + attackType + ", Scaling: " + scaling);
    }
}