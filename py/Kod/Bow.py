from Weapon import Weapon, WeaponMaterial
from typing import List, Tuple, Any

class Bow(Weapon):
    def __init__(self, name: str, level: int, tier: str, stats: List[Tuple[str, Any]], material: WeaponMaterial, 
                 arrows: int, range_val: float, draw_speed: float):
        super().__init__(name, level, tier, stats, material)
        self.arrows = arrows
        self.range = range_val
        self.draw_speed = draw_speed

    def specifics_info(self):
        return f"Arrows: {self.arrows}, Range: {self.range}, Draw Speed: {self.draw_speed}"