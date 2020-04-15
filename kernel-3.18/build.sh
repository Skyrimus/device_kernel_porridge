#!/bin/bash
rm -rf /root/kernel-3.18/out/arch/arm/boot/zImage-dtb
export KBUILD_BUILD_USER=skyrimus
export KBUILD_BUILD_HOST=4pda
export CROSS_COMPILE=/root/alps/t-alps-p0.mp2-V3.157/prebuilts/gcc/linux-x86/arm/arm-linux-androideabi-4.9/bin/arm-linux-androideabi-
export USE_CCACHE=1
export ARCH=arm
export TARGET=out
make O=$TARGET ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE porridge_defconfig
make O=$TARGET ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE -j12
if [ "$(find out/arch/arm/boot -name zImage-dtb)" != "" ]; then
cp /root/kernel-3.18/out/arch/arm/boot/zImage-dtb /root/split_img/boot.img-zImage
bash /root/repackimg.sh
else
echo -e '\e[31m'
echo "FAILED BLYAT SUKA"
echo ""
fi
