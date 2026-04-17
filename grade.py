import csv


def hitung_grade(akhir):
    if akhir >= 85:
        return 'A'
    elif akhir >= 70:
        return 'B'
    elif akhir >= 55:
        return 'C'
    elif akhir >= 40:
        return 'D'
    else:
        return 'E'


def main():
    try:
        with open("data.csv", "r", newline='', encoding='utf-8') as file:
            reader = csv.DictReader(file)

            total_nilai = 0
            jumlah_mhs = 0
            count_grade = {'A': 0, 'B': 0, 'C': 0, 'D': 0, 'E': 0}

            print("--- Detail Nilai Mahasiswa ---")
            print(f"{'Nama':<15} {'Tugas':<7} {'UTS':<7} {'UAS':<7} {'Akhir':<7} Grade")
            print("-" * 55)

            for row in reader:
                if not row:
                    continue
                try:
                    nama = row['Nama'].strip()
                    tugas = float(row['Tugas'])
                    uts = float(row['UTS'])
                    uas = float(row['UAS'])
                except (ValueError, KeyError, TypeError):
                    print(f"Skip baris error: {row}")
                    continue

                akhir = 0.3 * tugas + 0.3 * uts + 0.4 * uas
                grade = hitung_grade(akhir)

                print(f"{nama:<15} {tugas:<7.1f} {uts:<7.1f} {uas:<7.1f} {akhir:<7.2f} {grade}")

                total_nilai += akhir
                jumlah_mhs += 1
                count_grade[grade] += 1

    except FileNotFoundError:
        print("Error: data.csv tidak ditemukan!")
        return

    if jumlah_mhs > 0:
        rata_rata = total_nilai / jumlah_mhs
        print("\n--- Summary Kelas ---")
        print(f"Jumlah Mahasiswa : {jumlah_mhs}")
        print(f"Rata-rata Kelas : {rata_rata:.2f}")
        print(f"Jumlah Grade A : {count_grade['A']}")
        print(f"Jumlah Grade B : {count_grade['B']}")
        print(f"Jumlah Grade C : {count_grade['C']}")
        print(f"Jumlah Grade D : {count_grade['D']}")
        print(f"Jumlah Grade E : {count_grade['E']}")
    else:
        print("\nTidak ada data valid di file CSV.")


if __name__ == "__main__":
    main()
