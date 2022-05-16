/*
 Copyright 2022 Yury Bobylev <bobilev_yury@mail.ru>

 This file is part of Communist.
 Communist is free software: you can redistribute it and/or
 modify it under the terms of the GNU General Public License as
 published by the Free Software Foundation, either version 3 of
 the License, or (at your option) any later version.
 Communist is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 GNU General Public License for more details.
 You should have received a copy of the GNU General Public License
 along with Communist. If not,
 see <https://www.gnu.org/licenses/>.
 */

#include <gtkmm.h>
#include <gcrypt.h>
#include <libintl.h>
#include "CommunistApp.h"
#include "AuxFunc.h"

int
main (int argc, char *argv[])
{
  const char *rec = gcry_check_version (NULL);
  std::cout << "libgcrypt " << std::string (rec) << std::endl;
  std::string Sharepath;
  AuxFunc af;
  std::filesystem::path p (std::filesystem::u8path (af.get_selfpath ()));
  Sharepath = p.parent_path ().u8string () + "/../share/Communist";
  Sharepath = Sharepath + "/Translations.d";
  bindtextdomain ("Communist", Sharepath.c_str ());
  bind_textdomain_codeset ("Communist", "UTF-8");
  textdomain ("Communist");
  auto app = CommunistApp::create ();
  return app->run (argc, argv);
}
