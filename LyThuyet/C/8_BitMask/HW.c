#include <stdio.h>
#include <stdint.h>
#include <math.h>

uint8_t GIO_HANG = 0;       //0000 0000
typedef enum 
{
    AO          = 1 << 0,   //0000 0001
    QUAN        = 1 << 1,   //0000 0010
    VAY         = 1 << 2,   //0000 0100
    DAM         = 1 << 3,   //0000 1000
    NHAN        = 1 << 4,   //0001 0000
    VONG_TAY    = 1 << 5,   //0010 0000
    GIAY        = 1 << 6,   //0100 0000
    TUI         = 1 << 7    //1000 0000
}DO_DUNG_CA_NHAN;

void ADD_VAO_GIO_HANG(uint8_t *gio_hang, DO_DUNG_CA_NHAN tenhang){

    *gio_hang |= tenhang;

}

void CHECK_ITEM(uint8_t gio_hang, DO_DUNG_CA_NHAN tenhang){

    printf("Kiem tra san pham:\n");
    for (int i = 0; i < 8; i++)
    {
        if(tenhang & (1<<i)){
            if(i==0) (gio_hang & (1<<0)) ? printf("Ao da co\n") : printf("Ao chua co\n");
            if(i==1) (gio_hang & (1<<1)) ? printf("Quan da co\n") : printf("Quan chua co\n");
            if(i==2) (gio_hang & (1<<2)) ? printf("Vay da co\n") : printf("Vay chua co\n");
            if(i==3) (gio_hang & (1<<3)) ? printf("Dam da co\n") : printf("Dam chua co\n");
            if(i==4) (gio_hang & (1<<4)) ? printf("Nhan da co\n") : printf("Nhan chua co\n");
            if(i==5) (gio_hang & (1<<5)) ? printf("Vong tay da co\n") : printf("Vong tay chua co\n");
            if(i==6) (gio_hang & (1<<6)) ? printf("Giay da co\n") : printf("Giay chua co\n");
            if(i==7) (gio_hang & (1<<7)) ? printf("Tui da co\n") : printf("Tui chua co\n");
        }
    }
    

}

void SHOW_ITEM(uint8_t *giohang){
    printf("Cac vat pham da duoc them vao:\n");

    for (int i = 0; i < 8; i++)
    {
        if(*giohang & (1<<i)){
           if(i==0) printf("Ao\n");
           if(i==1) printf("Quan\n");
           if(i==2) printf("Vay\n");
           if(i==3) printf("Dam\n");
           if(i==4) printf("Nhan\n");
           if(i==5) printf("Vong tay\n");
           if(i==6) printf("Giay\n");
           if(i==7) printf("Tui\n");
        }
    }
    

}
int main(int argc, char const *argv[])
{
    //DO_DUNG_CA_NHAN a;
    ADD_VAO_GIO_HANG(&GIO_HANG, TUI|NHAN|VONG_TAY|VONG_TAY|VAY|DAM);

    //printf("%d", GIO_HANG);

    CHECK_ITEM(GIO_HANG, QUAN|NHAN|TUI);

    SHOW_ITEM(&GIO_HANG);
    return 0;
}
