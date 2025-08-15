#!/bin/bash
qemu-system-x86_64 \
  -kernel output/images/bzImage \
  -append "root=/dev/vda console=ttyS0" \
  -drive file=output/images/rootfs.ext2,format=raw,if=virtio \
  -nographic

