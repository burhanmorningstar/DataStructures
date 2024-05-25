# Öğrenci Bilgi Yönetim Sistemi

Bu proje, öğrenci bilgilerini dosyalardan okuyup bir ikili arama ağacında saklayan ve bu ağaçlar üzerinde çeşitli işlemler yapabilen bir C++ programıdır. Program, öğrenci bilgilerini listeleme, arama ve silme işlemlerini destekler. Ayrıca, ağaç verilerini dosyalara kaydedebilir.

## Dosya Yapısı

- `main.cpp`: Programın ana dosyası. Kullanıcı arayüzü ve menü işlemleri burada bulunur.
- `BinaryTree.cpp`: İkili arama ağacı fonksiyonlarının uygulamaları.
- `dosyadan_oku.cpp`: Dosya okuma işlemleri ve ikili arama ağacına veri ekleme işlemlerini içerir.

## Kullanım

### Derleme ve Çalıştırma

1. Projeyi derlemek için aşağıdaki komutu kullanın:

    ```bash
    g++ -o ogrenci_programi main.cpp BinaryTree.cpp dosyadan_oku.cpp
    ```

2. Programı çalıştırmak için:

    ```bash
    ./ogrenci_programi
    ```

### Program Kullanımı

Program çalıştırıldığında, aşağıdaki menü seçenekleri sunulur:

1. **Arama Yapmak (A)**:
   - **Derinlik Öncelikli Arama (DFS)**: Öğrenci numarasına göre ağaçta derinlik öncelikli arama yapar.
   - **Genişlik Öncelikli Arama (BFS)**: Öğrenci numarasına göre ağaçta genişlik öncelikli arama yapar.

2. **Listeleme (L)**:
   - **Preorder Listeleme (R)**: Ağacı preorder şeklinde ekrana yazar.
   - **Inorder Listeleme (I)**: Ağacı inorder şeklinde ekrana yazar.
   - **Postorder Listeleme (O)**: Ağacı postorder şeklinde ekrana yazar.

3. **Öğrenci Silme (S)**:
   - Öğrenci numarasını girerek ağactan öğrenci silme işlemi yapar.

4. **Dosyaya Yazma (Y)**:
   - Ağaçtaki verileri ilgili dosyalara kaydeder (`output1.txt`, `output2.txt`, `output3.txt`).

5. **Çıkış (C)**:
   - Programdan çıkar.

### Dosya İşlemleri

- **Veri Dosyaları**: Program `data1.txt`, `data2.txt` ve `data3.txt` dosyalarından öğrenci bilgilerini okur. Bu dosyalar her satırda bir öğrenci bilgisi içermelidir. Her öğrenci bilgisi öğrenci numarası, adı ve soyadı olmak üzere üç alan içermelidir ve bu alanlar tab karakteri ile ayrılmalıdır.

- **Çıktı Dosyaları**: Program `output1.txt`, `output2.txt` ve `output3.txt` dosyalarına ağaçtaki verileri kaydeder. Bu dosyalar da her satırda bir öğrenci bilgisi içerecek şekilde oluşturulur.

### Örnek Dosya Formatı

**data1.txt**:
```
123456   Ahmet   Yılmaz
234567   Ayşe    Demir
345678   Mehmet  Çelik
```

**data2.txt** ve **data3.txt** dosyaları da benzer formatta olmalıdır.

## Notlar

- Program, dosya işlemleri sırasında herhangi bir hata kontrolü yapmaz. Dosyaların doğru formatta olduğundan emin olunmalıdır.
- Derleme ve çalıştırma sırasında `g++` derleyicisinin ve `C++11` standardının yüklü olduğundan emin olunmalıdır.

