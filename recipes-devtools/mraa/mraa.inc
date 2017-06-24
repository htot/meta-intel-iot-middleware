SUMMARY = "Low Level Skeleton Library for Communication on Intel platforms"
SECTION = "libs"
AUTHOR = "Brendan Le Foll, Tom Ingleby"

LICENSE = "MIT"
LIC_FILES_CHKSUM = "file://COPYING;md5=66493d54e65bfc12c7983ff2e884f37f"

S = "${WORKDIR}/git"

inherit distutils-base pkgconfig python-dir cmake

PACKAGES =+ "python-${PN} node-${PN}"

# python-mraa package containing Python bindings
FILES_python-${PN} = "${PYTHON_SITEPACKAGES_DIR}/ \
                      ${datadir}/mraa/examples/python/ \
                      ${prefix}/src/debug/${BPN}/${PV}-${PR}/build/src/python/ \
                     "
                   
RDEPENDS_python-${PN} += "python"
INSANE_SKIP_python-${PN} = "debug-files"

# node-mraa package containing Nodejs bindings
FILES_node-${PN} = "${libdir}/node_modules/ \
                    ${datadir}/mraa/examples/javascript/ \
                    "
                    
RDEPENDS_node-${PN} += "nodejs"
INSANE_SKIP_node-${PN} = "debug-files"


FILES_${PN}-doc += "${datadir}/mraa/examples/"

FILES_${PN}-dbg += "${libdir}/node_modules/mraajs/.debug/ \
                    ${PYTHON_SITEPACKAGES_DIR}/.debug/"

PACKAGECONFIG ??= "python nodejs"
PACKAGECONFIG[python] = "-DBUILDSWIGPYTHON=ON, -DBUILDSWIGPYTHON=OFF, swig-native python,"
PACKAGECONFIG[nodejs] = "-DBUILDSWIGNODE=ON, -DBUILDSWIGNODE=OFF, swig-native nodejs,"

EXTRA_OECMAKE_append = " -DINSTALLGPIOTOOL=ON -DPYTHON_SITE_DIR:FILEPATH=${PYTHON_SITEPACKAGES_DIR} -DBASE_LIB_INSTALL_DIR=${base_libdir} -DCMAKE_SKIP_RPATH=ON"


do_compile_prepend () {
  # when yocto builds in ${D} it does not have access to ../git/.git so git
  # describe --tags fails. In order not to tag our version as dirty we use this
  # trick
  sed -i 's/-dirty//' src/version.c
}
