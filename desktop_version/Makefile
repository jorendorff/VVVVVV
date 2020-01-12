HEADERS=\
	$(cd src; ls *.h) \
	$(RUST_HEADER)

C_OBJECT_FILES=\
	../third_party/physfs/physfs.o \
	../third_party/physfs/physfs_archiver_dir.o \
	../third_party/physfs/physfs_archiver_unpacked.o \
	../third_party/physfs/physfs_archiver_zip.o \
	../third_party/physfs/physfs_byteorder.o \
	../third_party/physfs/physfs_platform_posix.o \
	../third_party/physfs/physfs_platform_unix.o \
	../third_party/physfs/physfs_unicode.o

CXX_OBJECT_FILES=\
	../third_party/tinyxml/tinystr.o \
	../third_party/tinyxml/tinyxml.o \
	../third_party/tinyxml/tinyxmlerror.o \
	../third_party/tinyxml/tinyxmlparser.o \
	src/BinaryBlob.o \
	src/BlockV.o \
	src/Ent.o \
	src/Entity.o \
	src/FileSystemUtils.o \
	src/Finalclass.o \
	src/Game.o \
	src/Graphics.o \
	src/GraphicsResources.o \
	src/GraphicsUtil.o \
	src/Input.o \
	src/KeyPoll.o \
	src/Labclass.o \
	src/Logic.o \
	src/Map.o \
	src/Music.o \
	src/Otherlevel.o \
	src/Screen.o \
	src/Script.o \
	src/Scripts.o \
	src/SoundSystem.o \
	src/Spacestation2.o \
	src/SteamNetwork.o \
	src/TerminalScripts.o \
	src/Textbox.o \
	src/Tower.o \
	src/UtilityClass.o \
	src/WarpClass.o \
	src/editor.o \
	src/main.o \
	src/preloader.o \
	src/titlerender.o

COMMON_FLAGS=-Os -I vvvvvv_pieces -I /usr/local/Cellar/sdl2_mixer/2.0.4/include/SDL2 -I /usr/local/Cellar/sdl2/2.0.10/include/SDL2 -I ../third_party/physfs -I ../third_party/tinyxml -D PHYSFS_SUPPORTS_DEFAULT=0 -D PHYSFS_SUPPORTS_ZIP=1 -D PHYSFS_PLATFORM_POSIX=1 -D PHYSFS_PLATFORM_UNIX=1 -D PHYSFS_NO_CDROM_SUPPORT=1
CXXFLAGS=$(COMMON_FLAGS)
CFLAGS=$(COMMON_FLAGS)

LDFLAGS=-lc -lSDL2 -lSDL2_mixer -Xlinker -dead_strip

all: vvvvvv

clean:
	rm -f $(C_OBJECT_FILES) $(CXX_OBJECT_FILES)
	rm -f vvvvvv

RUST_HEADER=vvvvvv_pieces/vvvvvv_pieces.h

RUST_LIB=vvvvvv_pieces/target/debug/libvvvvvv_pieces.a

all: vvvvvv

%.o: %.c
	clang $(CFLAGS) -o $@ -c $<

%.o: %.cpp $(HEADERS)
	clang++ $(CFLAGS) -o $@ -c $<

$(RUST_HEADER): $(RUST_LIB)

$(RUST_LIB): .FORCE
	cd vvvvvv_pieces && cargo build

vvvvvv: $(C_OBJECT_FILES) $(CXX_OBJECT_FILES) $(RUST_LIB)
	clang++ $(LDFLAGS) -o vvvvvv $^

.FORCE:

.PHONY: .FORCE all clean
