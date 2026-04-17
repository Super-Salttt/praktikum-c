import math

# Pastikan list history diletakkan di luar fungsi agar tersimpan terus
history = []

def calculate():
    print("--- Kalkulator v2 (Ketik 'exit' untuk keluar) ---")
    while True:
        expr = input("\nMasukkan operasi (contoh: 2 ** 3 atau akar 16): ")
        
        # Mengubah input ke lowercase agar lebih fleksibel
        if expr.lower() == 'exit':
            print("\nRiwayat Kalkulasi:")
            for h in history: 
                print(h)
            break

        tokens = expr.split()
        
        try:
            # Fitur Akar: format "akar 16"
            if tokens[0].lower() == 'akar':
                val = float(tokens[1])
                res = math.sqrt(val)
                result_str = f"akar({val}) = {res}"
            
            # Fitur Operasi Umum: format "angka op angka"
            elif len(tokens) == 3:
                a = float(tokens[0])
                op = tokens[1]
                b = float(tokens[2])
                
                if op == '+': res = a + b
                elif op == '-': res = a - b
                elif op == '*': res = a * b
                elif op == '/': res = a / b if b != 0 else "Error: Pembagian nol"
                elif op == '**': res = a ** b # Operasi pangkat
                else: res = "Operator tidak dikenal"
                
                result_str = f"{a} {op} {b} = {res}"
            else:
                result_str = "Format salah. Gunakan: '2 + 3' atau 'akar 16'"

            print(result_str)
            # Hanya simpan hasil kalkulasi yang valid ke history
            if 'res' in locals() and isinstance(res, (int, float)):
                history.append(result_str)

        except Exception as e:
            print(f"Error: Pastikan format input benar. Contoh: '10 * 5'")

if __name__ == "__main__":
    calculate()