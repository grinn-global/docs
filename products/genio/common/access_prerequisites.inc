This section outlines the requirements for accessing the board after it has been successfully flashed.

.. note::

    The following instructions assume you are using Ubuntu 22.04 LTS.

A serial connection allows you to access the device's console directly from your host system.

Ensure the following:

- The board is powered on.
- A USB cable is connected between the board’s Debug USB port and your host system.
- A terminal emulator (e.g., ``minicom``) is installed on your host system.

To install Minicom, run the following commands:

.. code-block:: bash

    sudo apt update
    sudo apt install minicom
