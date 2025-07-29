This section details the steps for flashing your device. Ensure you've completed the prerequisites and set up the ``fastboot`` tool as described in the previous section.

.. note::
    To obtain the latest firmware image, either build it from source or download it from the official repository.

    See previous sections for details on building or downloading the image.

Connect the board
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
  `Manually enabling download mode`_.

Successful flash procedure will report multiple erase and write cycles
resulting in no errors.

DTBO
----
By default basic video, GPU and APU DTBOs are loaded.

All available DTBOs can be listed using command:

.. code-block::

    genio-flash --list-dtbo


and selected using ``--load-dtbo`` switch.

.. admonition:: Loading DTBO example

  To flash the |BOARD_NAME| with DTBO for Sony IMX214 cameras
  connected to CSI0 and CSI1 the following command can be used:

  .. code-block::

    genio-flash -d 2 --load-dtbo camera-imx214-csi0-imx214-csi1.dtbo

``genio-flash`` also provides interactive interface to select
DTBOs which is enabled using ``-I`` switch.

Manually enabling download mode
*******************************

The |BOARD_NAME| can be switched into download mode manually
using buttons.

|IMG_BUTTON|

The following sequence should be used:

1. Press and keep **Download** button pressed.

2. Press and release **Reset** button.

3. Keep **Download** pressed until ``Erasing 'mmc0'``  is shown.
