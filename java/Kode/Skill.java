import java.util.UUID;

public class Skill {
    private String name;
    private int manaCost;
    private double cooldown;
    private Type skillType; // Association to Type
    private UUID id;

    public Skill(String name, int manaCost, double cooldown, Type skillType) {
        this.name = name;
        this.manaCost = manaCost;
        this.cooldown = cooldown;
        this.skillType = skillType;
        this.id = UUID.randomUUID(); 
    }

    public String getName() {
        return name;
    }

    public void displaySkillDetails() {
        System.out.println("  - [SKILL] Name: " + name + ", Mana Cost: " + manaCost + ", Cooldown: " + cooldown + "s");
        if (skillType != null) {
            System.out.print("    Type Details: ");
            skillType.displayType();
            System.out.println();
        }
    }
}