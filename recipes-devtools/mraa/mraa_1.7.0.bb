require mraa.inc

SRC_URI = "git://github.com/intel-iot-devkit/mraa.git;protocol=git;tag=v1.7.0 \
           file://0001-intel_edison_fab-enable-support-for-vanilla-kernels-.patch \
          "

DEPENDS = "nodejs swig-native json-c"
