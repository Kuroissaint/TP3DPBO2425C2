import java.util.List;
import java.util.ArrayList;

public class Character {
    private String username;
    private int level;
    private String job;
    private int hp;
    private int mana;
    private Weapon equippedWeapon; // Association to Weapon (Polymorphic)
    private List<Skill> learnedSkills; // Association to Skill

    public Character(String username, int level, String job, int hp, int mana) {
        this.username = username;
        this.level = level;
        this.job = job;
        this.hp = hp;
        this.mana = mana;
        this.learnedSkills = new ArrayList<>();
    }

    public void equipWeapon(Weapon weapon) {
        this.equippedWeapon = weapon;
    }

    public void learnSkill(Skill skill) {
        this.learnedSkills.add(skill);
    }

    public String getUsername() {
        return username;
    }

    public void displayCharacter() {
        System.out.println("  [INFO] Username: " + username + ", Job: " + job + ", Level: " + level);
        System.out.println("  [STATS] HP: " + hp + ", Mana: " + mana);

        System.out.println("\n  --- EQUIPPED WEAPON (Association) ---");
        if (equippedWeapon != null) {
            // Polymorphism: Java akan memanggil displayWeaponDetails dari subclass yang tepat
            equippedWeapon.displayWeaponDetails(false); // fullDetail = false (tanpa material)
        } else {
            System.out.println("  No weapon equipped.");
        }

        System.out.println("\n  --- LEARNED SKILLS (Association) ---");
        if (learnedSkills.isEmpty()) {
            System.out.println("  No skills learned.");
        } else {
            for (Skill skill : learnedSkills) {
                skill.displaySkillDetails();
            }
        }
    }
}