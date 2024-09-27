/*

Buatlah sebuah aplikasi penambahan dengan input berbasis Serial
  • "Input A:" (Enter)
  • "Input B:" (Enter)
  • "Total (A+B) ="

  https://wokwi.com/projects/410095541422389249

*/

int A = 0; // Deklarasi variabel A bernilai 0 dengan type integer
int B = 0; // Deklarasi variabel B bernilai 0 dengan type integer
int total = 0; // Deklarasi variabel total bernilai 0 dengan type integer
bool inputA_status = false;  // Flag untuk mengetahui apakah Input A sudah diterima
bool inputB_status = false;  // Flag untuk mengetahui apakah Input B sudah diterima

void setup() {
  // Memulai komunikasi serial dengan baud rate 115200
  Serial.begin(115200);
  
  // Menampilkan pesan permintaan input pertama
  Serial.print("Input A:");
}

void loop() {
  // Mengecek apakah data tersedia di Serial Monitor
  if (Serial.available() > 0) {
    // Membaca data dari input serial
    String input = Serial.readStringUntil('\n');
    input.trim();  // Menghilangkan spasi tambahan atau karakter newline
    
    // Jika Input A belum diterima, simpan data tersebut sebagai A
    if (!inputA_status) {
      A = input.toInt();  // Mengonversi input string menjadi integer
      Serial.println(A);  // Menampilkan nilai input A
      inputA_status = true;  // Tandai bahwa nilai input A sudah diterima
      Serial.print("Input B:");  // Minta input B
    }
    // Jika Input A sudah diterima dan Input B belum diterima
    else if (inputA_status && !inputB_status) {
      B = input.toInt();  // Mengonversi input string menjadi integer
      Serial.println(B);  // Menampilkan nilai input B
      inputB_status = true;  // Tandai bahwa nilai input B sudah diterima
    }
    
    // Jika kedua input sudah diterima, akan dilakukan penjumlahan dan menampilkan hasil
    if (inputA_status && inputB_status) {
      total = A + B;
      Serial.print("Total (A + B) = ");
      Serial.println(total);  // Tampilkan hasil penjumlahan
      
      // Reset untuk menerima input baru
      inputA_status = false;
      inputB_status = false;
      Serial.print("Input A:");  // Minta input baru untuk A
    }
  }
}

