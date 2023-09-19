#ifndef __VIRTIO_H__
#define __VIRTIO_H__

#include <stdint.h>
#include <uart.h>

#define VIRTIO_MMIO_BASE 0x10001000

// See https://docs.oasis-open.org/virtio/virtio/v1.1/virtio-v1.1.pdf
// See 4.2.2 MMIO Device Register Layout & 4.2.4 Legacy interface
#define VIRTIO_MMIO_MAGIC_VALUE        0x000
#define VIRTIO_MMIO_VERSION            0x004
#define VIRTIO_MMIO_DEVICE_ID          0x008
#define VIRTIO_MMIO_VENDOR_ID          0x00c
#define VIRTIO_MMIO_HOST_FEATURES      0x010
#define VIRTIO_MMIO_HOST_FEATURES_SEL  0x014
#define VIRTIO_MMIO_GUEST_FEATURES     0x020
#define VIRTIO_MMIO_GUEST_FEATURES_SEL 0x024
#define VIRTIO_MMIO_GUEST_PAGE_SIZE    0x028
#define VIRTIO_MMIO_QUEUE_SEL          0x030
#define VIRTIO_MMIO_QUEUE_NUM_MAX      0x034
#define VIRTIO_MMIO_QUEUE_NUM          0x038
#define VIRTIO_MMIO_QUEUE_ALIGN        0x03c
#define VIRTIO_MMIO_QUEUE_PFN          0x040
#define VIRTIO_MMIO_QUEUE_NOTIFY       0x050
#define VIRTIO_MMIO_INTERRUPT_STATUS   0x060
#define VIRTIO_MMIO_INTERRUPT_ACK      0x064
#define VIRTIO_MMIO_STATUS             0x070

#define VIRTIO_MAGIC 0x74726976

// legacy
#define VIRTIO_VERSION 0x1

// See 5 Device Types
#define VIRTIO_DEVICE_ID_BLK 0x2

// See https://github.com/qemu/qemu/blob/master/include/hw/virtio/virtio-mmio.h#L42
#define VIRTIO_VENDOR_ID_QEMU 0x554d4551

// See 2.1 Device Status Field
#define VIRTIO_STATUS_ACKNOWLEDGE        1
#define VIRTIO_STATUS_DRIVER             2
#define VIRTIO_STATUS_DRIVER_OK          4
#define VIRTIO_STATUS_FEATURES_OK        8
#define VIRTIO_STATUS_DEVICE_NEEDS_RESET 64
#define VIRTIO_STATUS_FAILED             128

// See 5.2.3 Feature bits
#define VIRTIO_BLK_F_BARRIER      0  // legacy
#define VIRTIO_BLK_F_SIZE_MAX     1
#define VIRTIO_BLK_F_SEG_MAX      2
#define VIRTIO_BLK_F_GEOMETRY     4
#define VIRTIO_BLK_F_RO           5
#define VIRTIO_BLK_F_BLK_SIZE     6
#define VIRTIO_BLK_F_SCSI         7  // legacy
#define VIRTIO_BLK_F_FLUSH        9
#define VIRTIO_BLK_F_WCE          9  // legacy, alias of VIRTIO_BLK_F_FLUSH
#define VIRTIO_BLK_F_TOPOLOGY     10
#define VIRTIO_BLK_F_CONFIG_WCE   11
#define VIRTIO_BLK_F_DISCARD      13
#define VIRTIO_BLK_F_WRITE_ZEROES 14

#endif