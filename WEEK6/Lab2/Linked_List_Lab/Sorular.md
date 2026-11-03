# Veri Yapıları Laboratuvarı — Tek Yönlü Bağlı Liste (C)

## Genel kurallar
- Her soru bağımsız bir C dosyasıdır. C11 standardını kullanın.
- Yalnızca TODO ile işaretlenmiş fonksiyon gövdelerini tamamlayın. Yapı tanımı, bellek ayırma, yazdırma, liste temizleme ve main hazırdır.
- `head` ilk düğümü gösterir; boş liste `NULL` ile temsil edilir. Son düğümün `next` alanı `NULL` olmalıdır.
- Global değişken, diziye dönüştürme veya hazır liste kütüphanesi kullanmayın.
- Başlangıç dosyalarında gövdeler bilinçli olarak boştur; fonksiyonlar tamamlanmadan çalıştırmayın. Özellikle değer döndüren boş fonksiyonlar geçerli bir sonuç üretmez.
- Verilen main fonksiyonları örnek senaryolardır; çözümünüz herhangi bir tamsayı ve liste uzunluğu için çalışmalıdır.

## Soru 1 — Sona ekleme ve düğüm sayma (Kolay)
`01_append_count.c` dosyasında `append` ve `countNodes` fonksiyonlarını tamamlayın.

1. `append(Node **head, int value)` yeni düğümü listenin sonuna eklemelidir. Boş listeye eklemeyi de desteklemelidir. `createNode` hazır verilmiştir.
2. `countNodes(const Node *head)` listedeki düğüm sayısını döndürmelidir. Boş liste için sonuç 0 olmalıdır. Listeyi değiştirmemelidir.

Örnek: Boş listeye sırasıyla 10, 20, 30 eklenince `10 -> 20 -> 30 -> NULL` elde edilir; düğüm sayısı 3 olur.

## Soru 2 — İlk eşleşmenin konumunu bulma (Kolay)
`02_search.c` dosyasında `findFirst(const Node *head, int target)` fonksiyonunu tamamlayın.

Hedef değerin ilk görüldüğü konumu döndürün. İlk düğümün konumu 0'dır. Değer yoksa veya liste boşsa -1 döndürün. Listeyi değiştirmeyin.

Örnek: `10 -> 20 -> 30 -> 20 -> NULL` için 20 aranırsa sonuç 1, 99 aranırsa -1 olmalıdır. Tekrarlanan değerlerde ilk eşleşme alınır.

## Soru 3 — İlk eşleşen düğümü silme (Orta)
`03_delete_first.c` dosyasında `deleteFirst(Node **head, int target)` fonksiyonunu tamamlayın.

Hedef değeri taşıyan yalnızca ilk düğümü silin. Silinen düğümün belleğini `free` ile bırakın. Silme gerçekleşirse 1, değer bulunamazsa 0 döndürün. Baş düğüm silinirse `head` güncellenmelidir. Boş liste, tek düğümlü liste, baş/orta/son düğüm ve tekrarlanan değerler doğru ele alınmalıdır.

Örnek: `10 -> 20 -> 30 -> 20 -> NULL` listesinden 20 silinince `10 -> 30 -> 20 -> NULL` elde edilir ve 1 döner. Listede olmayan 99 silinmeye çalışılırsa liste değişmez ve 0 döner.

## Soru 4 — Listeyi yerinde ters çevirme (Orta)
`04_reverse.c` dosyasında `reverseList(Node **head)` fonksiyonunu tamamlayın.

Bağlantıların yönünü değiştirerek listeyi ters çevirin ve baş işaretçisini güncelleyin. Yeni düğüm oluşturmayın, düğüm verilerini değiştirmeyin, dizi/özyineleme kullanmayın. Ek alan O(1) olmalıdır. Boş ve tek düğümlü listeler de çalışmalıdır.

Örnek: `10 -> 20 -> 30 -> 40 -> NULL` ters çevrilince `40 -> 30 -> 20 -> 10 -> NULL` olur. İkinci kez ters çevrilince başlangıç sırası geri gelmelidir.

## Derleme ve çalıştırma
Tamamladığınız dosyayı (örneğin soru 1) terminalde derleyin:

```sh
gcc -std=c11 -Wall -Wextra student/01_append_count.c -o question1
./question1
```

Windows PowerShell'de çalıştırma komutu: `.\question1.exe` (derlemede `-o question1.exe` kullanın).
