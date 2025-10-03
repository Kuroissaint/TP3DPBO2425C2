from Weapon import Weapon, WeaponMaterial
from typing import List, Tuple, Any

class Staff(Weapon):
    def __init__(self, name: str, level: int, tier: str, stats: List[Tuple[str, Any]], material: WeaponMaterial, 
                 spelling_speed: float, element: str):
        super().__init__(name, level, tier, stats, material)
        self.spelling_speed = spelling_speed
        self.element = element

    def specifics_info(self):
        return f"Element: {self.element}, Spelling Speed: {self.spelling_speed}"