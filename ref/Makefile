#CFLAGS += -mavx2 -mbmi2 -mpopcnt -maes -march=native -mtune=native -O3 -fomit-frame-pointer -D KYBER_90S -DKYBER_K=3
#ccflags-y := -g -std=gnu99 -mavx2 -mbmi2 -mpopcnt -maes -march=native -mtune=native -O3 -D KYBER_90S -DKYBER_K=3
ccflags-y := -g -Wall -Wextra -Wpedantic -Wmissing-prototypes -Wredundant-decls -Wshadow -Wpointer-arith -DKYBER_K=4 
#-O3
all:
	make -C /lib/modules/`uname -r`/build M=$(PWD) modules
#obj-m += kem.o indcpa.o polyvec.o poly.o fq.o shuffle.o ntt.o invntt.o basemul.o consts.o rejsample.o cbd.o verify.o aes256ctr.o randombytes.o test_kyber.o
#test_kyber-objs := kem.o indcpa.o polyvec.o poly.o basemul.o consts.o rejsample.o cbd.o verify.o aes256ctr.o randombytes.o test_kyber_main.o 
#test_kyber-y := fq.o shuffle.o ntt.o invntt.o
kkyber-objs := kex.o kem.o indcpa.o polyvec.o poly.o ntt.o cbd.o reduce.o verify.o fips202.o symmetric-shake.o randombytes.o test_kyber_main.o
obj-m += kkyber.o 
clean:
	rm -rf *.o *.ko *.mod.c .an* .lab* .tmp_versions Module.oymvers Module.markers modules.order .*.cmd *.mod
