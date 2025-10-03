import sys
from typing import List, Any
# Import SEMUA kelas
from Type import Type
from WeaponMaterial import WeaponMaterial
from Skill import Skill
from Weapon import Weapon
from Character import Character
from Bow import Bow
from Sword import Sword
from Staff import Staff
from HybridWeapon import HybridWeapon


# ===============================================
# GLOBAL STATE (Penyimpanan Data)
# ===============================================
characters: List[Character] = []
weapons: List[Weapon] = []
skills: List[Skill] = []
types: List[Type] = []

# ===============================================
# FUNGSI UTILITY INPUT
# ===============================================

def get_input(prompt, input_type=str):
    """ Utility untuk input yang lebih aman dan type-casting. """
    while True:
        try:
            value = input(prompt)
            if input_type == int:
                return int(value)
            elif input_type == float:
                return float(value)
            return value
        except ValueError:
            print("Input tidak valid. Silakan masukkan angka.")
        except EOFError:
            print("\nInput dibatalkan.")
            return None

def choose_item(item_list, item_name):
    """ Utility untuk memilih item dari list global. """
    if not item_list:
        print(f"\nBelum ada {item_name} yang terdaftar.")
        return None
    
    print(f"\n--- Pilih {item_name} yang Tersedia ---")
    for i, item in enumerate(item_list):
        if item_name == "Weapon":
            print(f"{i + 1}. {item.name} (Lvl {item.level})")
        else:
            print(f"{i + 1}. {item.name}")
    
    choice = get_input(f"Pilih nomor {item_name} (atau 0 untuk tidak pilih): ", int)
    
    if choice is None or choice < 1 or choice > len(item_list):
        return None
    
    return item_list[choice - 1]

def select_and_combine_type():
    """ Fungsi untuk membuat objek Type baru dari 3 pilihan user. """
    print("\n--- Membentuk Tipe Baru ---")

    # Damage Type
    print("\n--- Pilih Damage Type ---")
    dmg_choices = {1: "Physical", 2: "Magical"}
    for k, v in dmg_choices.items(): print(f"{k}. {v}")
    choice = get_input("Pilihan: ", int)
    dmg = dmg_choices.get(choice)
    if not dmg: return None

    # Attack Type
    print("\n--- Pilih Attack Type ---")
    atk_choices = {1: "Melee", 2: "Range"}
    for k, v in atk_choices.items(): print(f"{k}. {v}")
    choice = get_input("Pilihan: ", int)
    atk = atk_choices.get(choice)
    if not atk: return None
    
    # Scaling
    print("\n--- Pilih Scaling Stat ---")
    scl_choices = {1: "STR", 2: "INT", 3: "DEX"}
    for k, v in scl_choices.items(): print(f"{k}. {v}")
    choice = get_input("Pilihan: ", int)
    scl = scl_choices.get(choice)
    if not scl: return None
    
    new_type = Type(dmg, atk, scl)
    types.append(new_type)
    return new_type

# ===============================================
# FUNGSI TAMBAH DATA (COMMANDS 4, 5, 6)
# ===============================================

def add_character():
    print("\n--- Tambah Data Character ---")
    u = get_input("Username: ")
    j = get_input("Job: ")
    l = get_input("Level: ", int)
    hp = get_input("HP: ", int)
    m = get_input("Mana: ", int)
    
    new_char = Character(u, l, j, hp, m)
    characters.append(new_char)
    
    print("\n--- Pemilihan Weapon ---")
    selected_weapon = choose_item(weapons, "Weapon")
    if selected_weapon:
        new_char.equip_weapon(selected_weapon)
        print(f"Weapon {selected_weapon.name} di-equip.")
    
    print("\n--- Pemilihan Skill ---")
    selected_skill = choose_item(skills, "Skill")
    if selected_skill:
        new_char.learn_skill(selected_skill)
        print(f"Skill {selected_skill.name} dipelajari.")

    print(f"\nKarakter '{u}' berhasil dibuat.")


def add_weapon():
    print("\n--- Tambah Data Weapon ---")
    
    selected_type = select_and_combine_type()
    if not selected_type: return

    w_type = get_input("\nJenis Weapon (Bow/Sword/Staff/Hybrid/Other): ").lower()
    n = get_input("Nama Weapon: ")
    l = get_input("Level: ", int)
    
    # Material (Composition)
    mt_r = get_input("Material Rarity: ")
    mt_q = get_input("Material Quality: ")
    mat = WeaponMaterial(mt_r, mt_q)

    weapon_tier = selected_type.damage_type 

    if w_type == "bow":
        arr = get_input("Arrows: ", int)
        rng = get_input("Range: ", float)
        ds = get_input("Draw Speed: ", float)
        weapons.append(Bow(n, l, weapon_tier, [], mat, arr, rng, ds))
        
    elif w_type == "sword":
        sh = get_input("Sharpness: ", float)
        ass = get_input("Attack Speed: ", float)
        bc = get_input("Block Chance: ", float)
        weapons.append(Sword(n, l, weapon_tier, [], mat, sh, ass, bc))
        
    elif w_type == "staff":
        ss = get_input("Spelling Speed: ", float)
        e = get_input("Element: ")
        weapons.append(Staff(n, l, weapon_tier, [], mat, ss, e))
        
    elif w_type == "hybrid":
        # Data placeholder (default) - Wajib 0/None
        arr = rng = bow_ds = swd_sh = swd_as = swd_bc = stf_ss = 0.0
        stf_e = "None"
        
        # --- Tanyakan Komponen ---
        print("\n--- PILIH KOMPONEN HYBRID (Maksimal 2 dari Bow/Sword/Staff) ---")
        comp1 = get_input("Pilih komponen pertama (Bow/Sword/Staff): ").lower()
        comp2 = get_input("Pilih komponen kedua (Bow/Sword/Staff): ").lower()
        
        if comp1 == "bow" or comp2 == "bow":
            print("\n-- Input Data Bow --")
            arr = get_input("Arrows: ", int)
            rng = get_input("Range: ", float)
            bow_ds = get_input("Draw Speed: ", float)
        
        if comp1 == "sword" or comp2 == "sword":
            print("\n-- Input Data Sword --")
            swd_sh = get_input("Sharpness: ", float)
            swd_as = get_input("Attack Speed: ", float)
            swd_bc = get_input("Block Chance: ", float)
            
        if comp1 == "staff" or comp2 == "staff":
            print("\n-- Input Data Staff --")
            stf_ss = get_input("Spelling Speed: ", float)
            stf_e = get_input("Element: ")
        
        # Data Hybrid Tambahan
        cf = f"{comp1.capitalize()} & {comp2.capitalize()}"
        eff = get_input("\nEffect Hybrid: ")

        weapons.append(HybridWeapon(
            n, l, weapon_tier, [], mat, 
            arr, rng, bow_ds, 
            swd_sh, swd_as, swd_bc, 
            stf_ss, stf_e, 
            cf, eff, selected_type
        ))
        
    else:
        # Default Weapon
        weapons.append(Weapon(n, l, weapon_tier, [], mat))
    
    print(f"Weapon '{n}' berhasil ditambahkan.")

def add_skill():
    print("\n--- Tambah Data Skill ---")
    
    selected_type = select_and_combine_type()
    if not selected_type: return

    n = get_input("\nNama Skill: ")
    mc = get_input("Mana Cost: ", int)
    cd = get_input("Cooldown: ", float)
    
    skills.append(Skill(n, mc, cd, selected_type))
    print(f"Skill '{n}' berhasil ditambahkan.")

# ===============================================
# FUNGSI DISPLAY (COMMANDS 1, 2, 3)
# ===============================================

def display_all(item_list, title, display_func, **kwargs):
    print(f"\n================= [ SEMUA {title.upper()} ] =================")
    if not item_list:
        print(f"Belum ada {title} yang terdaftar.")
        return
    
    for i, item in enumerate(item_list):
        print(f"\n--- {title.upper()} #{i + 1} ---")
        display_func(item, **kwargs)
    print(f"\n========================================================")

# ===============================================
# MAIN MENU
# ===============================================

def main():    
    while True:
        print("\n\n=============== MENU APLIKASI RPG ================")
        print("1. Tampilkan Character")
        print("2. Tampilkan Weapon")
        print("3. Tampilkan Skill")
        print("------------------------------------------------")
        print("4. Tambah Data Character")
        print("5. Tambah Data Weapon")
        print("6. Tambah Data Skill")
        print("------------------------------------------------")
        print("0. Keluar")
        
        choice = get_input("Pilih Perintah: ", int)
        
        if choice == 1: 
            display_all(characters, "Character", lambda c: c.display_character())
        elif choice == 2: 
            display_all(weapons, "Weapon", lambda w: w.display_weapon_details(full_detail=True))
        elif choice == 3: 
            display_all(skills, "Skill", lambda s: s.display_skill_details())
        elif choice == 4: 
            add_character()
        elif choice == 5: 
            add_weapon()
        elif choice == 6: 
            add_skill()
        elif choice == 0:
            print("Terima kasih. Program berakhir.")
            break
        else:
            print("Pilihan tidak ada. Silakan coba lagi.")

if __name__ == "__main__":
    main()