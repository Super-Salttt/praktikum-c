# guess_py_level.py
import random
import os

def load_best_score():
    if os.path.exists("best_score.txt"):
        with open("best_score.txt", "r") as f:
            return int(f.read())
    return 9999

def save_best_score(score):
    with open("best_score.txt", "w") as f:
        f.write(str(score))

def play(min_v=1, max_v=100):
    secret = random.randint(min_v, max_v)
    attempts = 0
    print(f"Tebak angka antara {min_v} sampai {max_v}!")
    while True:
        try:
            guess = int(input("Masukkan tebakan: "))
        except ValueError:
            print("Input bukan angka, coba lagi.")
            continue
        attempts += 1
        if guess < secret:
            print("Terlalu kecil.")
        elif guess > secret:
            print("Terlalu besar.")
        else:
            print(f"Benar! Kamu menebak dalam {attempts} percobaan.")
            return attempts

def main():
    best = load_best_score()
    print("=== GAME TEBAK ANGKA ===")
    print(f"Best Score saat ini: {best if best != 9999 else 'Belum ada'}")
    
    print("\nPilih Level:")
    print("1. Easy   (1-10)")
    print("2. Medium (1-100)") 
    print("3. Hard   (1-1000)")
    level = input("Masukkan pilihan 1/2/3: ")

    if level == '1':
        min_v, max_v = 1, 10
    elif level == '3':
        min_v, max_v = 1, 1000
    else:
        min_v, max_v = 1, 100

    score = play(min_v, max_v)
    
    if score < best:
        print(f"REKOR BARU! Skor terbaik: {score}")
        save_best_score(score)
    else:
        print(f"Skor terbaik tetap: {best}")

if __name__ == "__main__":
    main()