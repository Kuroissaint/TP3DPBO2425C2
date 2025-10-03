import uuid
from typing import List, Tuple, Any
from WeaponMaterial import WeaponMaterial

class Weapon:
    """ Kelas Dasar untuk semua senjata (Inheritance & Polymorphism Base). """
    def __init__(self, name: str, level: int, tier: str, stats: List[Tuple[str, Any]], material: WeaponMaterial):
        self.name = name
        self.level = level
        self.tier = tier
        self.stats = stats
        self.material = material  # Composition
        self.id = uuid.uuid4() 

    def display_weapon_details(self, full_detail=True):
        print(f"  [WEAPON] Name: {self.name} (Lvl {self.level}, Tier: {self.tier})")
        
        if full_detail and self.material:
            print("  --- Material (Composition) ---")
            self.material.display_material()
        
        info = self.specifics_info()
        if info:
            print(f"  Specifics: {info}")
        
    def specifics_info(self):
        """ Di-override oleh subclass untuk memberikan detail spesifik. """
        return ""