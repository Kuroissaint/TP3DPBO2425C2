### Janji 
---
Saya dengan nama Nafis Asyakir Anjar dan Nim 2407915 mengerjakan tugas praktikum 3 dalam mata kuliah Desain dan Pemrograman Berorientasi Objek untuk keberkahan-Nya maka saya tidak akan melakukan kecurangan seperti yang telah di spesifikasikan Aamiin.

---
### Desain dan penjelasan atribut dan method setiap kelas

Di TP 3 kali ini saya membawakan tema Character Game RPG dengan class sebagai berikut:

1. Character (Class Utama)
   Atribut :
   - Username -> Nama dari karakter
   - Level    -> Parameter kekuatan dari karakter
   - Job      -> Role khusus setiap karakter yang menjadi karakteristik unik character, menentukan weapon dan skill yang kompatibel
   - HP       -> Jumlah darah yang dimiliki oleh karakter
   - Mana     -> Semacam energi yang digunakan untuk melancarkan skill

   Method  :
   - Getter
   - Setter
   - Equip_weapon (Menggunakan data dari Weapon)
   - Learn_skill (Menggunakan data dari Skill)
   - Print
     
2. Weapon
   Atribut :
   - Name -> Nama senjata
   - Level -> Parameter kekuatan senjata
   - Tier -> Kategorisasi kekuatan senjata
   - Stats -> Statistik senjata

  Method : 
  - Getter
  - Setter
  - Print
  - Info detail senjata (Menggunakan virtual inheritance untuk persiapan polimorfisme)

3. Weapon Material
   Atribut :
   Rarity -> Kelangkaan material dari senjata
   Quality -> Kualitas material senjata

   Method :
   - Getter
   - Setter
   - Print

4. Bow
   Atribut :
   - Arrows -> Jumlah anak panah yang bisa disimpan (Sebelum reload)
   - Range -> Jarak tembakan anak panah
   - DrawSpeed -> Kecepatan penarikan anak panah sebelum menembak

   Method :
   - Getter
   - Setter
   - Info Spesifik (Menampilkan info detail -> Override dari method serupa di Weapon)
   - Print
     
5. Sword
   Atribut :
   - Sharpness -> Ketajaman pedang
   - AttackSpeed -> Kecepatan ayunan pedang
   - BlockChance -> Rate untuk menahan serangan melee musuh

    Method :
   - Getter
   - Setter
   - Info Spesifik (Menampilkan info detail -> Override dari method serupa di Weapon)
   - Print
     
6. Staff
   Atribut :
   - SpellingSpeed -> Peningkatan Kecepatan Rapalan
   - Element -> Atribut tambahan serangan

   Method :
   - Getter
   - Setter
   - Info Spesifik (Menampilkan info detail -> Override dari method serupa di Weapon)
   - Print

7. Hybrid Weapon
   Atribut :
   - Combined From -> Gabungan dari senjata apa senjata tersebut
   - Effect -> Efek tambahan dari senjata hybrid

   Method :
   - Getter
   - Setter
   - Info Spesifik (Menampilkan info detail -> Override dari method serupa dari Weapon, dan weapon asal hybridnya)
   - Print
8. Skill
   Atribut :
   - Name -> Nama dari skill
   - ManaCost -> Jumlah mana yang terkonsumsi oleh skill
   - Cooldown -> Lama waktu menunggu hingga skill bisa digunakan kembali

   Method :
   - Getter
   - Setter
   - Print

9. Type
   Atribut :
   - Damage Type -> Tipe damage serangan (Physical/Magical)
   - Attack Type -> Tipe metode serangan (Melee/Ranged)
   - Scaling -> Berdasarkan apa damage dari serangan tersebut (STR/INT/DEX)

   Method :
   - Getter
   - Setter
   - Print
---
### Penjelasan Desain

Inheritance :
  - Hierarchical Inheritance
    (Weapon) --> (Bow)(Sword)(Staff)
    
    Bow, Sword, dan Staff merupakan inheritance dari class Weapon karena memiliki atribut yang bisa diturunkan dan sama secara objek.
  - Multiple Inheritance
    (Bow)(Sword)(Staff) --> (HybridWeapon)

    HybridWeapon mendapatkan inheritance berdasarkan Weapon dasar pembentukan HybridWeapon tersebut. Selain itu, secara objek mereka sama, dan memiliki atribut yang dapat diturunkan berdasarkan Weapon dasar pembentuk hybrid.

  - Hierarchical Inheritance dan Multiple Inheritance di atas juga membentuk Hybrid Inheritance.

Composition :
  - (Weapon Material) --> (Weapon)

    Weapon tidak akan ada tanpa Material Weapon dan Material Weapon akan tetap ada meskipun tidak dibuat menjadi Weapon.

Assosiation :
  - (Character) --> (Weapon)

    Character mengambil data yang berada di class Weapon berdasarkan Weapon yang digunakan
    
  - (Character) --> (Skill)

    Character mengambil data yang berada di class Skill berdasarkan Skill yang dipelajari

  - (Hybrid Weapon) --> (Type)

    Hybrid Weapon mengambil data yang berada di class Type berdasarkan tipe Weapon
    
  - (Skill) --> (Type)

    Skill mengambil data yang berada di class Type berdasarkan tipe skill

---

### Penjelasan Alur

- Pertama User akan memulai melalui file Main
- Kemudian semua class akan diimport sehingga definisi semua class tersedia di file main
- Inisialisasi AoO (Vector untuk cpp dan list) untuk menyimpan data yang akan dibuat
- Kemudian masuk ke dalam looping

- Ketika masuk looping user akan diminta untuk memilih 7 opsi
  
  1. Tampilkan Character
  2. Tampilkan Weapon
  3. Tampilkan Skill
  4. Tambah Data Character
  5. Tambah Data Weapon
  6. Tambah Data Skill
  7. Keluar

- Kemudian Berdasarkan opsi yang dipilih user ia akan menjalankan fungsi-fungsi tertentu

  Untuk Print Character ia juga akan menampilkan Weapon yang digunakan (tanpa material) dan Skill yang dimiliki
  Untuk Print Weapon, hanya menampilkan list Weapon secara spesifik
  Untuk Print SKill, hanya menampilkan list Skill secara spesifik
  
- Ketika keluar semua data akan hilang

---
### Dokumentasi

Sebelum :

Cpp --

![cpp1](https://github.com/user-attachments/assets/8e91775b-c739-44f8-ad10-9ea8e529f182)

Py --

![py](https://github.com/user-attachments/assets/b8289591-c228-4997-9dfc-61230994d5da)

Java --

![java1](https://github.com/user-attachments/assets/26e0f3ae-2e64-4c50-bff9-de3722be1b6c)

Proses Input :

Cpp --

![cpp2](https://github.com/user-attachments/assets/307d1a4f-ea9c-4453-9f31-3cf061e5ca71)
![cpp3](https://github.com/user-attachments/assets/35f5060f-894c-45e1-a597-0ff0afa64009)
![cpp4](https://github.com/user-attachments/assets/1f7a8ae6-913f-4d8f-ba23-39ebad01687b)

Py --

![py2](https://github.com/user-attachments/assets/d9263e71-cad2-42ca-9bcb-3a3569bde3e0)
![py3](https://github.com/user-attachments/assets/70b3aaf2-60a1-488e-90d3-3f3f42a2e2a9)

Java --

![java2](https://github.com/user-attachments/assets/4c46c2da-b9e1-4460-a67d-4f26cfa4cc5f)

Hasil akhir :

Cpp --

![cpp5](https://github.com/user-attachments/assets/032d660a-bd09-407d-82da-d642af5b018f)

Py --

![py4](https://github.com/user-attachments/assets/0965e545-538b-4685-8fac-34e1c2227cea)

Java --

![java3](https://github.com/user-attachments/assets/5ca08a2e-43d9-4c7c-848f-b17c25f5d7fa)


---

### Udahan Pliss, Sekian dan Terima kasih, RAWRRRRRRRRRR


    


    



