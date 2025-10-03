from Weapon import Weapon, WeaponMaterial
from typing import List, Tuple, Any

class Sword(Weapon):
    def __init__(self, name: str, level: int, tier: str, stats: List[Tuple[str, Any]], material: WeaponMaterial, 
                 sharpness: float, attack_speed: float, block_chance: float):
        super().__init__(name, level, tier, stats, material)
        self.sharpness = sharpness
        self.attack_speed = attack_speed
        self.block_chance = block_chance

    def specifics_info(self):
        return f"Sharpness: {self.sharpness}, Attack Speed: {self.attack_speed}, Block Chance: {self.block_chance}"