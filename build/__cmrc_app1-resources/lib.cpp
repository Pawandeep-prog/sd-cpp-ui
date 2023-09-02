        #include <cmrc/cmrc.hpp>
#include <map>
#include <utility>

namespace cmrc {
namespace app1 {

namespace res_chars {
// These are the files which are available in this resource library
// Pointers to fonts/Chalkduster.ttf
extern const char* const f_3a24_fonts_Chalkduster_ttf_begin;
extern const char* const f_3a24_fonts_Chalkduster_ttf_end;
}

namespace {

const cmrc::detail::index_type&
get_root_index() {
    static cmrc::detail::directory root_directory_;
    static cmrc::detail::file_or_directory root_directory_fod{root_directory_};
    static cmrc::detail::index_type root_index;
    root_index.emplace("", &root_directory_fod);
    struct dir_inl {
        class cmrc::detail::directory& directory;
    };
    dir_inl root_directory_dir{root_directory_};
    (void)root_directory_dir;
    static auto f_980d_fonts_dir = root_directory_dir.directory.add_subdir("fonts");
    root_index.emplace("fonts", &f_980d_fonts_dir.index_entry);
    root_index.emplace(
        "fonts/Chalkduster.ttf",
        f_980d_fonts_dir.directory.add_file(
            "Chalkduster.ttf",
            res_chars::f_3a24_fonts_Chalkduster_ttf_begin,
            res_chars::f_3a24_fonts_Chalkduster_ttf_end
        )
    );
    return root_index;
}

}

cmrc::embedded_filesystem get_filesystem() {
    static auto& index = get_root_index();
    return cmrc::embedded_filesystem{index};
}

} // app1
} // cmrc
    