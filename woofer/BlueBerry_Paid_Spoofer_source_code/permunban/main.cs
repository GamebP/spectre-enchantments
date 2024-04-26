using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Http;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using Anti_DebugNET.AntiDebugTools;
using KeyAuth;
using System.Drawing.Imaging;
using Helix_Spoofer;
using Code7777;

namespace permunban
{
    public partial class main : Form
    {

        public static api KeyAuthApp = new api(
            name: "Loader",
            ownerid: "lQDfKzMKbn",
            secret: "27628f5fcbb27653282e433d3828b61c15c465c0f26f1e572ec77b547e2052a2",
            version: "1.0"
        );
        public main()
        {
            InitializeComponent();
            KeyAuthApp.init();
        }
        static class permexe
        {
            static int[] keyC = { 7, 11, 8, 13, 12, 6, 4, 9, 5, 15, 17, 19, 16, 2, 14, 18, 3, 20, 10, 1 };
            static int[] keyV = { 5, 6, 4, 1, 2, 3 };
            static int[] keyN = { 10, 8, 6, 1, 7, 5, 3, 4, 9, 2 };
            static string consonants = "bcdfghjklmnpqrstvwxz";
            static string vowels = "aeiouy";

            public static string Encrypt(string s)
            {
                if (String.IsNullOrEmpty(s)) return s;

                int lenC = (s.Length - 1) % 15;
                int lenV = (s.Length - 1) % 8;
                int lenN = (s.Length - 1) % 12;

                char[] ca = new char[s.Length];

                for (int i = 0; i < s.Length; i++)
                {
                    char c = s[i];

                    int j;

                    if ((j = vowels.IndexOf(c)) > -1)
                    {
                        j += keyV[(i + lenV) % 6];
                        if (j > 5) j -= 6;
                        ca[i] = vowels[j];
                    }
                    else if ((j = consonants.IndexOf(c)) > -1)
                    {
                        j += keyC[(i + lenC) % 20];
                        if (j > 19) j -= 20;
                        ca[i] = consonants[j];
                    }
                    else if ((j = vowels.ToUpper().IndexOf(c)) > -1)
                    {
                        j += keyV[(i + lenV) % 6];
                        if (j > 5) j -= 6;
                        ca[i] = vowels.ToUpper()[j];
                    }
                    else if ((j = consonants.ToUpper().IndexOf(c)) > -1)
                    {
                        j += keyC[(i + lenC) % 20];
                        if (j > 19) j -= 20;
                        ca[i] = consonants.ToUpper()[j];
                    }
                    else if (c >= 48 && c <= 57)
                    {
                        j = c + keyN[(i + lenN) % 10];
                        if (j > 57) j -= 10;
                        ca[i] = (char)j;
                    }
                    else
                    {
                        ca[i] = c;
                    }
                }

                return new string(ca);
            }

            public static string Decrypt(string s)
            {
                if (String.IsNullOrEmpty(s)) return s;

                int lenC = (s.Length - 1) % 15;
                int lenV = (s.Length - 1) % 8;
                int lenN = (s.Length - 1) % 12;

                char[] ca = new char[s.Length];

                for (int i = 0; i < s.Length; i++)
                {
                    char c = s[i];
                    int j;
                    if ((j = vowels.IndexOf(c)) > -1)
                    {
                        j -= keyV[(i + lenV) % 6];
                        if (j < 0) j += 6;
                        ca[i] = vowels[j];
                    }
                    else if ((j = consonants.IndexOf(c)) > -1)
                    {
                        j -= keyC[(i + lenC) % 20];
                        if (j < 0) j += 20;
                        ca[i] = consonants[j];
                    }
                    else if ((j = vowels.ToUpper().IndexOf(c)) > -1)
                    {
                        j -= keyV[(i + lenV) % 6];
                        if (j < 0) j += 6;
                        ca[i] = vowels.ToUpper()[j];
                    }
                    else if ((j = consonants.ToUpper().IndexOf(c)) > -1)
                    {
                        j -= keyC[(i + lenC) % 20];
                        if (j < 0) j += 20;
                        ca[i] = consonants.ToUpper()[j];
                    }
                    else if (c >= 48 && c <= 57)
                    {
                        j = c - keyN[(i + lenN) % 10];
                        if (j < 48) j += 10;
                        ca[i] = (char)j;
                    }
                    else
                    {
                        ca[i] = c;
                    }
                }
                return new string(ca);
            }
        }
        private void guna2Button2_Click(object sender, EventArgs e)
        {
            Login main = new Login();
            main.Show();
            this.Hide();
        }

        private void main_Load(object sender, EventArgs e)
        {
            expiry.Text = "Expiry: " + UnixTimeToDateTime(long.Parse(Login.KeyAuthApp.user_data.subscriptions[0].expiry));
            username.Text = "Username: " + Login.KeyAuthApp.user_data.username;
            KeyAuthApp.init();
        }
        public DateTime UnixTimeToDateTime(long unixtime)
        {
            System.DateTime dtDateTime = new DateTime(1970, 1, 1, 0, 0, 0, 0, System.DateTimeKind.Local);
            dtDateTime = dtDateTime.AddSeconds(unixtime).ToLocalTime();
            return dtDateTime;
        }
        private void guna2Button3_Click(object sender, EventArgs e)
        {
            {
                byte[] result = Login.KeyAuthApp.download("864741");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\amifldrv64.sys", result);

                byte[] result2 = Login.KeyAuthApp.download("409676");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\PermDatShit.bat", result2);

                byte[] result3 = Login.KeyAuthApp.download("093523");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\AMIDEWINx64.exe", result3);
                // Maked by 44444 L
                Thread.Sleep(2000);
                Process.Start(@"C:\Windows\Performance\WinSAT\DataStore\ChangeDatShit.bat");
                Thread.Sleep(120000);
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\AMIDEWINx64.exe");
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\PermDatShit.bat");
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\amifldrv64.sys");
                WebClient webClient = new WebClient();
                webClient.DownloadFile("https://cdn.discordapp.com/attachments/1012134324650385439/1012141586823520406/Serials_Checker.bat", @"C:\Windows\Performance\WinSAT\DataStore\Serials_Checker.bat");

                // Maked by 44444 L

                System.Diagnostics.Process.Start(@"C:\Windows\Performance\WinSAT\DataStore\Serials_Checker.bat");
                System.Diagnostics.Process.Start("https://discord.gg/JAT7p8UMR9");
            }
            {
                byte[] result = Login.KeyAuthApp.download("561278");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\uddrivers.sys", result);

                byte[] result2 = Login.KeyAuthApp.download("273655");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\Mapper.exe", result2);

                byte[] result3 = Login.KeyAuthApp.download("736985");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\driverload.bat", result3);

                Thread.Sleep(2000);
                Process.Start(@"C:\Windows\Performance\WinSAT\DataStore\driverload.bat");
                Thread.Sleep(3300);
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\Mapper.exe");
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\driverload.bat");
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\uddrivers.sys");
                // Maked by 44444 L


                WebClient webClient = new WebClient();
                webClient.DownloadFile("https://cdn.discordapp.com/attachments/1012134324650385439/1012141586823520406/Serials_Checker.bat", @"C:\Windows\Performance\WinSAT\DataStore\Serials_Checker.bat");

                // Maked by 44444 L

                System.Diagnostics.Process.Start(@"C:\Windows\Performance\WinSAT\DataStore\Serials_Checker.bat");
                System.Diagnostics.Process.Start("https://discord.gg/JAT7p8UMR9");
            }
            {
                byte[] result = Login.KeyAuthApp.download("921912");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\randomize.sys", result);

                byte[] result2 = Login.KeyAuthApp.download("273655");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\Mapper.exe", result2);

                byte[] result3 = Login.KeyAuthApp.download("337722");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\Performance\WinSAT\DataStore\load.bat", result3);

                Thread.Sleep(2000);
                Process.Start(@"C:\Windows\Performance\WinSAT\DataStore\load.bat");
                Thread.Sleep(3300);
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\Mapper.exe");
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\load.bat");
                File.Delete(@"C:\Windows\Performance\WinSAT\DataStore\randomize.sys");

                // Maked by 44444 L

                WebClient webClient = new WebClient();
                webClient.DownloadFile("https://cdn.discordapp.com/attachments/1012134324650385439/1012141586823520406/Serials_Checker.bat", @"C:\Windows\Performance\WinSAT\DataStore\Serials_Checker.bat");



                System.Diagnostics.Process.Start(@"C:\Windows\Performance\WinSAT\DataStore\Serials_Checker.bat");
                System.Diagnostics.Process.Start("https://discord.gg/JAT7p8UMR9");
            }

        }
        // Maked by 44444 L
        private void guna2Button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Warning, close the Cleaner when it wants to Spoof/Clean bios.", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            WebClient webClient = new WebClient();
            webClient.DownloadFile("https://cdn.discordapp.com/attachments/1012134324650385439/1012134498206486690/1buttonBETA-custom.exe", @"C:\Windows\INF\1buttonBETA-custom.exe");

            // Maked by 44444 L

            System.Diagnostics.Process.Start(@"C:\Windows\INF\1buttonBETA-custom.exe");
            System.Diagnostics.Process.Start("https://discord.gg/JAT7p8UMR9");
        }

        private void guna2ControlBox1_Click(object sender, EventArgs e)
        {
            Environment.Exit(0);
            Application.Exit();
        }

        private void guna2Button3_Click_1(object sender, EventArgs e)
        {
            // Maked by 44444 L
        }

        private void guna2Button1_Click(object sender, EventArgs e)
        {
            // Maked by 44444 L
        }

        private void guna2Button1_Click_1(object sender, EventArgs e)
        {
            {
                {
                    byte[] result = Login.KeyAuthApp.download("365691");
                    if (!Login.KeyAuthApp.response.success)
                    {
                        MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                        Environment.Exit(0);
                    }
                    else
                        File.WriteAllBytes(@"C:\Windows\amifldrv64.sys", result);

                    byte[] result2 = Login.KeyAuthApp.download("290484");
                    if (!Login.KeyAuthApp.response.success)
                    {
                        MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                        Environment.Exit(0);
                    }
                    else
                        File.WriteAllBytes(@"C:\Windows\spoof.bat", result2);

                    byte[] result3 = Login.KeyAuthApp.download("306703");
                    if (!Login.KeyAuthApp.response.success)
                    {
                        MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                        Environment.Exit(0);
                    }
                    else
                        File.WriteAllBytes(@"C:\Windows\AMIDEWINx64.exe", result3);

                    byte[] result4 = Login.KeyAuthApp.download("425933");
                    if (!Login.KeyAuthApp.response.success)
                    {
                        MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                        Environment.Exit(0);
                    }
                    else
                        File.WriteAllBytes(@"C:\Windows\H2OSDE-Wx64.exe", result4);


                    Thread.Sleep(2000);
                    Process.Start(@"C:\Windows\spoof.bat");
                    Thread.Sleep(120000);
                    File.Delete(@"C:\Windows\AMIDEWINx64.exe");
                    File.Delete(@"C:\Windows\spoof.bat");
                    File.Delete(@"C:\Windows\amifldrv64.sys");
                    Scanner.ScanAndKill();
                    AntiCrack_DotNet.AntiVirtualization.BadVMFilesDetection();
                    AntiCrack_DotNet.AntiVirtualization.CheckForVMwareAndVirtualBox();
                    AntiCrack_DotNet.AntiVirtualization.BadVMProcessNames();
                    AntiCrack_DotNet.AntiVirtualization.CheckForHyperV();
                    AntiCrack_DotNet.AntiVirtualization.CheckForKVM();
                    AntiCrack_DotNet.AntiVirtualization.CrashingSandboxie();
                    AntiCrack_DotNet.AntiVirtualization.IsCuckooSandboxPresent();
                    AntiCrack_DotNet.AntiVirtualization.CheckForBlacklistedNames();
                    AntiCrack_DotNet.OtherChecks.IsKernelDebuggingEnabled();
                    AntiCrack_DotNet.OtherChecks.IsTestSignedDriversAllowed();
                    AntiCrack_DotNet.OtherChecks.IsUnsignedDriversAllowed();
                    AntiCrack_DotNet.AntiDllInjection.PatchLoadLibraryW();
                    AntiCrack_DotNet.AntiDllInjection.PatchLoadLibraryA();
                    AntiCrack_DotNet.AntiDllInjection.BinaryImageSignatureMitigationAntiDllInjection();
                    // Maked by 44444 L
                    da.AntiDLL.Load();
                    AntiDump.Initialize();


                }
            }
        }
        private void guna2Button3_Click_2(object sender, EventArgs e)
        {
            {
                byte[] result = Login.KeyAuthApp.download("823835");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\driver.sys", result);

                byte[] result2 = Login.KeyAuthApp.download("549286");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\kdmapper.exe", result2);

                byte[] result3 = Login.KeyAuthApp.download("665565");
                if (!Login.KeyAuthApp.response.success)
                {
                    MessageBox.Show("Error: " + Login.KeyAuthApp.response.message);
                    Environment.Exit(0);
                }
                else
                    File.WriteAllBytes(@"C:\Windows\driverLoader.bat", result3);

                Process.Start(@"C:\Windows\driverLoader.bat");
                Spoof sh = new Spoof();
                sh.Show();

                Thread.Sleep(1500);
                File.Delete(@"C:\Windows\kdmapper.exe");
                File.Delete(@"C:\Windows\driverLoader.bat");
                File.Delete(@"C:\Windows\driver.sys");
            }
        }

        private void guna2Button4_Click_1(object sender, EventArgs e)
        {
           
            MessageBox.Show("Warning, close the Cleaner when it wants to Spoof/Clean bios.", "Warning", MessageBoxButtons.OK, MessageBoxIcon.Warning);
            WebClient webClient = new WebClient();
            webClient.DownloadFile("https://cdn.discordapp.com/attachments/1045039459508436992/1045889956322746378/blueberry_cleaner.exe", @"C:\Windows\INF\blueberry_cleaner.exe");
            Process.Start(@"C:\Windows\INF\blueberry_cleaner.exe");
        }

        private void guna2Panel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void guna2Button6_Click(object sender, EventArgs e)
        {

        }

        private void guna2ShadowPanel2_Paint(object sender, PaintEventArgs e)
        {

        }

        private void guna2ShadowPanel3_Paint(object sender, PaintEventArgs e)
        {

        }

        private void username_Click(object sender, EventArgs e)
        {

        }

        private void label6_Click(object sender, EventArgs e)
        {

        }
    }
}
