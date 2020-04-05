#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DATA
{
  char nama[100], usia[100], nomorkamar[100], asal[100], jeniskelamin[100];
  struct DATA *next;
};


void isiDatabase (struct DATA *kosan);
void tampilkanDatabase (struct DATA *kosan);
void hapusDatabase (struct DATA *kosan);
void editDatabase (struct DATA *kosan);
void cariDatabase (struct DATA *kosan);

int
main ()
{
  struct DATA *kosan;

  kosan = (struct DATA *) malloc (sizeof (struct DATA));

  int pilihmenu = 0;

  while (pilihmenu != 8)
    {
      printf ("\n-- Database Kos --\n");

      printf ("Tekan 1. Buat Database Kos\n");
      printf ("Tekan 2. Menampilkan Isi Database Kos\n");
      printf ("Tekan 3. Menambah Data Baru ke Database Kos\n");
      printf ("Tekan 4. Menghapus Data di Database Kos\n");
      printf ("Tekan 5. Mengedit Data di Database Kos\n");
      printf ("Tekan 6. Mencari Data di Database Kos\n");
      printf ("Tekan 7. Mengurutkan Data di Database Kos\n");
      printf ("Tekan 8. Keluar dari Program\n");
      printf ("Mana yang Anda pilih? ");
      scanf ("%d", &pilihmenu);


      switch (pilihmenu)
	{
	case 1:
	  isiDatabase (kosan);
	  break;
	  // buat database kos
	case 2:
	  // tampilkan isi database kos
	  tampilkanDatabase (kosan);
	  break;
	case 3:
	  // Menambah data baru ke database kos
	  isiDatabase (kosan);
	  break;
	case 4:
	  hapusDatabase (kosan);
	  // menghapus data di database kos

	  break;
	case 5:
	  //mengedit data di database kos
	  editDatabase (kosan);
	  break;
	case 6:
	  // mencari data di database kos
	  cariDatabase (kosan);
	  break;
	case 7:
	  // mengurutkan data di database kos
	  break;
	}
    }
  system ("pause");
  return (0);
}

void
isiDatabase (struct DATA *kosan)
{
  // Fungsi untuk membuat database
  printf ("Ada berapa data? ");
  int jmldata, l;
  scanf ("%d", &jmldata);
  char temp_nama[100], temp_jk[100], temp_nokamar[100], temp_umur[100],
    temp_asal[100];
  for (l = 0; l < jmldata; l++)
    {
      printf ("Masukkan data ke %d\n", l + 1);
      printf ("Nama\t\t: ");
      scanf ("%s", temp_nama);
      printf ("Umur\t\t: ");
      scanf ("%s", temp_umur);
      printf ("No kamar\t: ");
      scanf ("%s", temp_nokamar);
      printf ("Asal\t\t: ");
      scanf ("%s", temp_asal);
      printf ("Jenis Kelamin\t: ");
      scanf ("%s", temp_jk);

      while (kosan->next != NULL)
	kosan = kosan->next;

      kosan->next = (struct DATA *) malloc (sizeof (struct DATA));
      memcpy (kosan->next->nama, temp_nama, 100);
      memcpy (kosan->next->usia, temp_umur, 100);
      memcpy (kosan->next->nomorkamar, temp_nokamar, 100);
      memcpy (kosan->next->jeniskelamin, temp_jk, 100);
      memcpy (kosan->next->asal, temp_asal, 100);
    }


}

void
tampilkanDatabase (struct DATA *kosan)
{
  //Fungsi untuk menampilkan database
  while (kosan->next != NULL)
    {
      printf ("%s  %s  %s  %s  %s\n", kosan->nama, kosan->usia,
	      kosan->nomorkamar, kosan->jeniskelamin, kosan->asal);
      kosan = kosan->next;
    }
  printf ("%s  %s  %s  %s  %s\n", kosan->nama, kosan->usia, kosan->nomorkamar,
	  kosan->jeniskelamin, kosan->asal);
}

void
hapusDatabase (struct DATA *kosan)
{
  // Fungsi untuk menghapus database
  struct DATA *temp;
  temp = (struct DATA *) malloc (sizeof (struct DATA));

  char hps_nokamar[20];
  printf ("Masukkan nomor kamar yang ingin dihapus datanya : ");
  scanf ("%s", hps_nokamar);

  if (strcmp (kosan->nomorkamar, hps_nokamar) == 0)
    {
      temp = kosan->next;
      free (kosan);
      kosan = temp;
    }
  else
    {
      while (strcmp (kosan->next->nomorkamar, hps_nokamar) != 0)
	kosan = kosan->next;

      temp = kosan->next->next;
      free (kosan->next);
      kosan->next = temp;
    }
}

void
editDatabase (struct DATA *kosan)
{
  printf ("Edit data kamar nomer berapa? ");
  char nokamar[20];
  scanf ("%s", nokamar);

    printf ("----------------- DATA -----------------------\n");
  printf ("Data nomer berapa yang mau diganti?\n");
  printf ("1. Nama\n");
  printf ("2. Umur\n");
  printf ("3. Nomor kamar\n");
  printf ("4. Asal\n");
  printf ("5. Jenis Kelamin\n");
  
printf ("Data nomer berapa yang mau diganti?\n");
  int no_data;
  scanf ("%d", &no_data);
     printf ("----------------------------------------\n");

  printf ("Diganti jadi apa? ");
  char datapgt[100];
  scanf ("%s", datapgt);
       printf ("----------------------------------------\n");

  if (no_data == 1)
    {
      //cari dan edit nama here
      while (kosan->next != NULL)
	{
	  if (strcmp (kosan->next->nomorkamar, nokamar) == 0)
	    {
	      memcpy (kosan->next->nama, datapgt, 100);
	    }
	  else
	    continue;

	  kosan = kosan->next;
	}
    }
  else if (no_data == 2)
    {
      // cari dan edit umur here
      while (kosan->next != NULL)
	{
	  if (strcmp (kosan->next->nomorkamar, nokamar) == 0)
	    {
	      memcpy (kosan->next->usia, datapgt, 100);
	    }
	  else
	    continue;

	  kosan = kosan->next;
	}
    }
  else if (no_data == 3)
    {
      //cari dan edit nomor kamar here
      while (kosan->next != NULL)
	{
	  if (strcmp (kosan->next->nomorkamar, nokamar) == 0)
	    {
	      memcpy (kosan->next->nomorkamar, datapgt, 100);
	    }
	  else
	    continue;

	  kosan = kosan->next;
	}
    }
  else if (no_data == 4)
    {
      //cari dan edit asal here
      while (kosan->next != NULL)
	{
	  if (strcmp (kosan->next->nomorkamar, nokamar) == 0)
	    {
	      memcpy (kosan->next->asal, datapgt, 100);
	    }
	  else
	    continue;

	  kosan = kosan->next;
	}
    }
  else if (no_data == 5)
    {
      //cari dan edit jenis kelamin here
      while (kosan->next != NULL)
	{
	  if (strcmp (kosan->next->nomorkamar, nokamar) == 0)
	    {
	      memcpy (kosan->next->jeniskelamin, datapgt, 100);
	    }
	  else
	    continue;

	  kosan = kosan->next;
	}
    }
  else
    printf ("Nomor tidak dikenali\n");

}

void
cariDatabase (struct DATA *kosan)
{
  int r = -1;
  int i = 1;

  printf ("Cari data kamar nomer berapa? ");
  char nokamar[20];
  scanf ("%s", nokamar);

  while (kosan->next != NULL)
    {
      if (strcmp (kosan->next->nomorkamar, nokamar) == 0)
	break;
      else
	i++;

      kosan = kosan->next;
    }

  printf ("Data ada di urutan nomer %d\n", i);
}
