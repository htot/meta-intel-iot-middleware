# meta-intel-iot-middleware

This is the middleware layer for the Intel IoT developer kit. Here are
middleware parts useful for the iot-devkit but not shipped as part of meta-oe
or backports from newer versions of meta-oe which are not appropriate for
meta-oe itself. Software in here is likely to follow a more agressive upgrade
schedule (FT - this is Intel's original text, and it's true if more agressive == less slow).

# What is here

  * **pyro** 
    
    The layer is not being supported anymore by intel and the useful recipes are being slowly moved upstream to
    meta-oe or other layers. As it is very inconvenient to have 2 linked layers,
    [https://github.com/htot/meta-intel-iot-middleware/tree/pyro](https://github.com/htot/meta-intel-iot-middleware/tree/pyro) is emptied and the contents have been moved to [https://github.com/htot/meta-intel-edison/tree/pyro64](https://github.com/htot/meta-intel-edison/tree/pyro64).