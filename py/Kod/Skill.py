import uuid
from Type import Type

class Skill:
    """ Merepresentasikan skill yang bisa dipelajari Character (Association). """
    def __init__(self, name: str, mana_cost: int, cooldown: float, skill_type: Type):
        self.name = name
        self.mana_cost = mana_cost
        self.cooldown = cooldown
        self.skill_type = skill_type # Association to Type
        self.id = uuid.uuid4()

    def display_skill_details(self):
        print(f"  - [SKILL] Name: {self.name}, Mana Cost: {self.mana_cost}, Cooldown: {self.cooldown}s")
        if self.skill_type:
            print("    Type Details: ", end="")
            self.skill_type.display_type()
            print()