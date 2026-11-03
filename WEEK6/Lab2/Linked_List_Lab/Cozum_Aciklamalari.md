# Eğitmen İçin Çözüm Açıklamaları

## 1. Sona ekleme ve sayma
Yeni düğüm oluşturulur. Liste boşsa baş işaretçisi bu düğüme yönlendirilir. Diğer durumda son düğüme kadar gidilir ve son düğümün next alanı yeni düğüme bağlanır. Sayma işleminde her düğüm bir kez ziyaret edilir.

`Node **head` kullanımı, çağıranın baş işaretçisini değiştirmeyi sağlar. Sayma yalnızca okuma yaptığı için `const Node *` yeterlidir. Sona ekleme O(n), sayma O(n) zamandır; yeni düğüm dışında ek alan O(1)'dir.

## 2. Arama
Başlangıçta konum 0'dır. Her düğümde değer karşılaştırılır. İlk eşleşmede konum hemen döndürülür; sona ulaşılırsa -1 döner. Böylece yinelenen değerlerin ilk konumu bulunur. En kötü durum O(n) zaman, O(1) ek alandır.

## 3. Silme
`current` aday düğümü, `previous` önceki düğümü tutar. Eşleşme yoksa 0 döner. Baş siliniyorsa `*head`, silinecek düğümün sonrasına alınır. Diğer durumda `previous->next`, `current->next` değerine ayarlanır. Bağlantı düzeltildikten sonra current serbest bırakılır. Serbest bırakılan düğüme tekrar erişilmez. En kötü durum O(n) zaman, O(1) ek alandır.

## 4. Ters çevirme
`previous` ters çevrilmiş bölümün başını, `current` sıradaki düğümü tutar. Önce orijinal sonraki düğüm `next` ile saklanır; sonra current->next geriye yönlendirilir. İşaretçiler ilerletilir. Döngü sonunda previous yeni baştır. Sonraki düğümü önceden saklamazsak listenin kalanına erişimi kaybederiz. O(n) zaman, O(1) ek alandır.

## Beklenen program çıktıları

### 01_append_count

```text
NULL
Count: 0
10 -> 20 -> 30 -> NULL
Count: 3
```

### 02_search

```text
Empty search: -1
10 -> 20 -> 30 -> 20 -> NULL
Find 10: 0
Find 20: 1
Find 99: -1
```

### 03_delete_first

```text
Delete from empty: 0
10 -> 20 -> 30 -> 20 -> NULL
Delete 20: 1
10 -> 30 -> 20 -> NULL
Delete 10: 1
30 -> 20 -> NULL
Delete 20: 1
30 -> NULL
Delete 99: 0
30 -> NULL
Delete 30: 1
NULL
```

### 04_reverse

```text
NULL
10 -> NULL
10 -> 20 -> 30 -> 40 -> NULL
40 -> 30 -> 20 -> 10 -> NULL
10 -> 20 -> 30 -> 40 -> NULL
```
