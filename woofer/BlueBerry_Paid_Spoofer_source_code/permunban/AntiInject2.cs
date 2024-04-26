using System;
using System.Diagnostics;
using System.Net;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Threading;
namespace da
{
    internal class AntiDLL
    {
        public static bool IfExecute;

        public static int total;

        public static int dlls;

        public static Timer _timer;

        public AntiDLL()
        {
        }

        public static void Check(bool Execute)
        {
            AntiDLL.IfExecute = Execute;
            AntiDLL._timer = new Timer(new TimerCallback(AntiDLL.TimerCallback), null, 0, 200);
        }

        [DllImport("psapi.dll", CharSet = CharSet.None, ExactSpelling = false)]
        public static extern bool EnumProcessModulesEx(IntPtr hProcess, [In][Out] IntPtr[] lphModule, int cb, out int lpcbNeeded, uint dwFilterFlag);

        public static void Load()
        {
            AntiDLL.EnumProcessModulesEx(Process.GetCurrentProcess().Handle, new IntPtr[] { IntPtr.Zero }, 0, out AntiDLL.total, 3);
        }

        public static string ReturnHWID()
        {
            return WindowsIdentity.GetCurrent().User.Value;
        }

        public static string ReturnIP()
        {
            return (new WebClient()).DownloadString("https://api64.ipify.org/");
        }

        public static string ReturnPC()
        {
            return Environment.UserName;
        }

        public static void Start()
        {
            Process.GetCurrentProcess().Kill();
        }

        public static void TimerCallback(object o)
        {

            if (!AntiDLL.IfExecute)
            {
                return;
            }
            AntiDLL.EnumProcessModulesEx(Process.GetCurrentProcess().Handle, new IntPtr[] { IntPtr.Zero }, 0, out AntiDLL.dlls, 3);
            if (AntiDLL.dlls != AntiDLL.total)
            {
                Console.Clear();
                Console.WriteLine("YOU CANT REVERSE YOU SKID!!!!!!!!!");
                AntiDLL.Start();
            }
        }
    }
}