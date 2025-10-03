class WeaponMaterial:
    """ Komponen (Composition) dari Weapon. """
    def __init__(self, rarity: str, quality: str):
        self.rarity = rarity
        self.quality = quality

    def display_material(self):
        print(f"  [MATERIAL] Rarity: {self.rarity}, Quality: {self.quality}")