SUMMARY = "Sensor/Actuator repository for Mraa"
SECTION = "libs"
AUTHOR = "Brendan Le Foll, Tom Ingleby, Yevgeniy Kiveisha"

TARGET_CPPFLAGS +="-fpermissive"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://LICENSE;md5=66493d54e65bfc12c7983ff2e884f37f"

DEPENDS = "nodejs swig-native mraa libjpeg-turbo"

SRC_URI = "git://github.com/intel-iot-devkit/upm.git;protocol=git;tag=v1.3.0 \
"

S = "${WORKDIR}/git"

inherit distutils-base pkgconfig python-dir cmake

FILES_${PN}-doc += "${datadir}/upm/examples/"

PACKAGECONFIG ??= "python nodejs"
PACKAGECONFIG[python] = "-DBUILDSWIGPYTHON=OFF, -DBUILDSWIGPYTHON=OFF, swig-native python"
PACKAGECONFIG[nodejs] = "-DBUILDSWIGNODE=OFF, -DBUILDSWIGNODE=OFF, swig-native nodejs"
