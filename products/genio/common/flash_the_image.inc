This section details the steps for flashing your device. Ensure you've completed the prerequisites and set up the ``fastboot`` tool as described in the previous section.

.. note::
    To obtain the latest firmware image, either build it from source or download a prebuilt image.

    See previous sections for details on building or downloading the image.

Connect the Board
*****************

Flashing |BOARD_NAME| requires:

- |POWER_SOURCE| power source,
- |USB_CONNECTIONS| connected to the host PC.

|IMG_USB|

Flashing
********

In terminal, go to the directory containing image files
and use the following command:

.. code-block::

    genio-flash -d 2

This command will write the image from the current working directory
into the |BOARD_NAME|.

.. note::
  The ``-d 2`` argument allows to automatically put the board into download
  mode.

  It can be omitted, however then the board must be put into download mode manually, as listed in the section
  `Download Mode`_.

Successful flash procedure will report multiple erase and write cycles
resulting in no errors.

Device Tree Blob Overlays
-------------------------

By default basic video, GPU and APU DTBOs are loaded.

All available DTBOs can be listed using the following command:

.. code-block::

    genio-flash --list-dtbo


To select a DTBO, use the ``--load-dtbo`` switch.

.. admonition:: Loading DTBO example

  To flash the |BOARD_NAME| with DTBO for Sony IMX214 cameras
  connected to CSI0 and CSI1 the following command can be used:

  .. code-block::

    genio-flash -d 2 --load-dtbo camera-imx214-csi0-imx214-csi1.dtbo

``genio-flash`` also provides interactive interface to select
DTBOs which can be invoked with the ``-I`` switch.

Download Mode
*************

The |BOARD_NAME| can be put into download mode manually using physical buttons.

|IMG_BUTTON|

The following sequence should be used:

1. Press and hold the **Download** button.

2. Press and release the **Reset** button.

3. Keep the **Download** button pressed until ``Erasing 'mmc0'``  is shown.
