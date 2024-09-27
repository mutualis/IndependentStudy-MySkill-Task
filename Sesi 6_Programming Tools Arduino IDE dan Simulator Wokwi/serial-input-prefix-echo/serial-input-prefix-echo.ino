/*

Buatlah sebuah program yang mampu menerima input Serial PC &
seketika langsung mengirimkannya kembali Serial PC dengan prefix "echo ".

  https://wokwi.com/projects/410007073444618241

*/

void setup() {
  // Memulai komunikasi serial dengan baud rate 115200
  Serial.begin(115200);

  // Pesan intruksi
  Serial.println("Masukkan karakter dari keyboard (tekan Enter setelah input):");
}

void loop() {
  // Mengecek apakah ada data yang dikirim dari keyboard
  if (Serial.available() > 0) {
    // Membaca satu karakter dari input serial
    String input = Serial.readString();

    // Menggabungkan "echo " dengan karakter yang diinput
    String output = "echo " + String(input);

    // Menampilkan hasil gabungan ke Serial Monitor
    Serial.println(output);
  }
}

