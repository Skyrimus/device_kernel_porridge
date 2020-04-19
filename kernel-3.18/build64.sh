#!/bin/bash
rm -rf /root/kernel-3.18/out/arch/arm64/boot/Image.gz-dtb
export KBUILD_BUILD_USER=skyrimus
export KBUILD_BUILD_HOST=4pda
export CROSS_COMPILE=/root/alps/t-alps-p0.mp2-V3.157/prebuilts/gcc/linux-x86/aarch64/aarch64-linux-gnu-6.3.1/bin/aarch64-linux-gnu-
export USE_CCACHE=1
export ARCH=arm64
export TARGET=out
make O=$TARGET ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE porridge_defconfig
make O=$TARGET ARCH=$ARCH CROSS_COMPILE=$CROSS_COMPILE -j12
if [ "$(find out/arch/arm64/boot -name Image.gz-dtb)" != "" ]; then
cp /root/kernel-3.18/out/arch/arm64/boot/Image.gz-dtb /root/x64/split_img/boot.img-zImage
bash /root/x64/repackimg.sh
else
echo -e '\e[31m'
echo "FAILED BLYAT SUKA"
echo ""
fi
