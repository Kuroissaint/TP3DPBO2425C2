from Weapon import Weapon
from Skill import Skill
from typing import List

class Character:
    def __init__(self, username: str, level: int, job: str, hp: int, mana: int):
        self.username = username
        self.level = level
        self.job = job
        self.hp = hp
        self.mana = mana
        self.equipped_weapon: Weapon = None # Association to Weapon
        self.learned_skills: List[Skill] = [] # Association to Skill

    def equip_weapon(self, weapon: Weapon):
        self.equipped_weapon = weapon

    def learn_skill(self, skill: Skill):
        self.learned_skills.append(skill)

    def display_character(self):
        print(f"  [INFO] Username: {self.username}, Job: {self.job}, Level: {self.level}")
        print(f"  [STATS] HP: {self.hp}, Mana: {self.mana}")

        print("\n  --- EQUIPPED WEAPON (Association) ---")
        if self.equipped_weapon:
            # Polymorphism: display_weapon_details dengan full_detail=False
            self.equipped_weapon.display_weapon_details(full_detail=False) 
        else:
            print("  No weapon equipped.")

        print("\n  --- LEARNED SKILLS (Association) ---")
        if not self.learned_skills:
            print("  No skills learned.")
        else:
            for skill in self.learned_skills:
                skill.display_skill_details()