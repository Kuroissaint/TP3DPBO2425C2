class Type:
    """ Merepresentasikan kombinasi Damage, Attack, dan Scaling Type. """
    def __init__(self, damage_type: str, attack_type: str, scaling: str):
        self.damage_type = damage_type
        self.attack_type = attack_type
        self.scaling = scaling

    def display_type(self):
        print(f"[TYPE] Damage: {self.damage_type}, Attack: {self.attack_type}, Scaling: {self.scaling}", end="")