CONFIG = gn_generator $$CONFIG
GN_SRC_DIR = $$PWD
isUniversal() {
    for(arch, QT_ARCHS) {
        GN_FILES += $$OUT_PWD/$$arch/$$getConfigDir()/BUILD.gn
    }
} else {
    GN_FILES = $$OUT_PWD/$$getConfigDir()/BUILD.gn
}
GN_FIND_MOCABLES_SCRIPT = $$shell_path($$QTWEBENGINE_ROOT/tools/scripts/gn_find_mocables.py)
GN_RUN_BINARY_SCRIPT = $$shell_path($$QTWEBENGINE_ROOT/tools/scripts/gn_run_binary.py)
GN_IMPORTS =  $$PWD/qtwebengine.gni
qtConfig(webengine-extensions) {
  GN_INCLUDES += $$PWD/qtwebengine_sources.gni $$PWD/qtwebengine_resources.gni $$PWD/common/extensions/api/qtwebengine_extensions_features.gni
} else {
  GN_INCLUDES = $$PWD/qtwebengine_sources.gni $$PWD/qtwebengine_resources.gni
}
GN_CORE_INCLUDE_DIRS = $$PWD/service
GN_CREATE_PRI = true
GN_PRECOMPILED_HEADERS = true
QMAKE_INTERNAL_INCLUDED_FILES = $$GN_IMPORTS $$GN_INCLUDES $$GN_FILE


