from Weapon import Weapon, WeaponMaterial
from Type import Type
from Bow import Bow
from Sword import Sword
from Staff import Staff
from typing import List, Tuple, Any

# Multiple Inheritance dari Bow, Sword, dan Staff
class HybridWeapon(Bow, Sword, Staff):
    """ Multiple Inheritance: Menggabungkan Bow, Sword, dan Staff. """
    def __init__(self, name: str, level: int, tier: str, stats: List[Tuple[str, Any]], material: WeaponMaterial, 
                 arr: int, rng: float, bow_ds: float, 
                 swd_sh: float, swd_as: float, swd_bc: float, 
                 stf_ss: float, stf_e: str, 
                 combined_from: str, effect: str, special_type: Type):
        
        # Panggil konstruktor kelas dasar Weapon secara eksplisit
        Weapon.__init__(self, name, level, tier, stats, material) 
        
        # Inisialisasi atribut spesifik
        self.arrows = arr
        self.range = rng
        self.draw_speed = bow_ds
        self.sharpness = swd_sh
        self.attack_speed = swd_as
        self.block_chance = swd_bc
        self.spelling_speed = stf_ss
        self.element = stf_e
        
        # Atribut Hybrid
        self.combined_from = combined_from
        self.effect = effect
        self.special_type = special_type # Association

    def specifics_info(self):
        # Mengumpulkan informasi spesifik yang diinput (non-zero/non-None)
        parts = []
        
        if self.arrows > 0 or self.range > 0 or self.draw_speed > 0:
            parts.append(f"[BOW] Arrows: {self.arrows}, Range: {self.range}, Draw Speed: {self.draw_speed}")
        
        if self.sharpness > 0 or self.attack_speed > 0 or self.block_chance > 0:
            parts.append(f"[SWORD] Sharpness: {self.sharpness}, Attack Speed: {self.attack_speed}, Block Chance: {self.block_chance}")
            
        if self.spelling_speed > 0 or self.element != "None":
            parts.append(f"[STAFF] Element: {self.element}, Spelling Speed: {self.spelling_speed}")

        hybrid_info = "\n  --- HYBRID (Multiple Inheritance) ---\n    " + "\n    ".join(parts)
        hybrid_info += f"\n  [HYBRID] Combined From: {self.combined_from}, Effect: {self.effect}"
        
        if self.special_type:
            hybrid_info += "\n  [TYPE] Special Type: "
            self.special_type.display_type() 
        return hybrid_info