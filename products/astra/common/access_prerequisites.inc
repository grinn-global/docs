This section outlines the requirements for accessing the board after it has been successfully flashed.

.. note::

    The following instructions assume you are using Ubuntu 22.04 LTS.

ADB (Android Debug Bridge) allows you to connect to and manage the board from your host system.
Ensure the following:

- The board is powered on.
- A USB cable is connected between the board’s Debug USB port and your host system.
- ``adb`` is installed on your host system.

To install ADB, open a terminal and run the following commands:

.. code-block:: bash

    sudo apt update
    sudo apt install adb
