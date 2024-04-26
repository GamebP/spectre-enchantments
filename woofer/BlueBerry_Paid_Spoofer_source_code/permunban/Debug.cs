using Discord.Webhook;
using System;
using System.Collections;
using System.Diagnostics;
using System.Net;
using System.Runtime.CompilerServices;
using System.Runtime.InteropServices;
using System.Security.Principal;
using System.Threading.Tasks;

namespace YullySpoofer
{
    internal static class Debug
    {
        private readonly static uint SPI_SETDESKWALLPAPER;

        private readonly static uint SPIF_UPDATEINIFILE;

        private readonly static uint SPIF_SENDWININICHANGE;

        static Debug()
        {
            YullySpoofer.Debug.SPI_SETDESKWALLPAPER = 20;
            YullySpoofer.Debug.SPIF_UPDATEINIFILE = 1;
            YullySpoofer.Debug.SPIF_SENDWININICHANGE = 2;
        }

        [DllImport("kernel32.dll", CharSet = CharSet.None, ExactSpelling = false)]
        private static extern bool CloseHandle(IntPtr handle);

        public static void Initialize()
        {
            if (Debugger.IsLogging())
            {
                YullySpoofer.Debug.SendMessage("DEBUGGING DETECTED / PUTTING KNEE ON NECK");
            }
            if (Debugger.IsAttached)
            {
                YullySpoofer.Debug.SendMessage("DEBUGGING DETECTED / PUTTING KNEE ON NECK");
            }
            if (Environment.GetEnvironmentVariable("complus_profapi_profilercompatibilitysetting") != null)
            {
                YullySpoofer.Debug.SendMessage("DEBUGGING DETECTED / PUTTING KNEE ON NECK");
            }
            if (string.Compare(Environment.GetEnvironmentVariable("COR_ENABLE_PROFILING"), "1", StringComparison.Ordinal) == 0)
            {
                YullySpoofer.Debug.SendMessage("DEBUGGING DETECTED / PUTTING KNEE ON NECK");
            }
            if (Environment.OSVersion.Platform != PlatformID.Win32NT)
            {
                return;
            }
            int[] numArray = new int[6];
            int num = 0;
            IntPtr handle = Process.GetCurrentProcess().Handle;
            if (YullySpoofer.Debug.NtQueryInformationProcess(handle, 31, numArray, 4, ref num) == 0 && numArray[0] != 1)
            {
                YullySpoofer.Debug.SendMessage("DEBUGGING DETECTED / PUTTING KNEE ON NECK");
            }
            if (YullySpoofer.Debug.NtQueryInformationProcess(handle, 30, numArray, 4, ref num) == 0 && numArray[0] != 0)
            {
                YullySpoofer.Debug.SendMessage("DEBUGGING DETECTED / PUTTING KNEE ON NECK");
            }
            if (YullySpoofer.Debug.NtQueryInformationProcess(handle, 0, numArray, 24, ref num) != 0)
            {
                return;
            }
            IntPtr intPtr = Marshal.ReadIntPtr(Marshal.ReadIntPtr((IntPtr)numArray[1], 12), 12);
            Marshal.WriteInt32(intPtr, 32, 0);
            IntPtr intPtr1 = Marshal.ReadIntPtr(intPtr, 0);
            IntPtr intPtr2 = intPtr1;
            do
            {
                intPtr2 = Marshal.ReadIntPtr(intPtr2, 0);
                if (Marshal.ReadInt32(intPtr2, 44) != 1572886 || Marshal.ReadInt32(Marshal.ReadIntPtr(intPtr2, 48), 0) != 7536749)
                {
                    continue;
                }
                IntPtr intPtr3 = Marshal.ReadIntPtr(intPtr2, 8);
                IntPtr intPtr4 = Marshal.ReadIntPtr(intPtr2, 12);
                Marshal.WriteInt32(intPtr4, 0, (int)intPtr3);
                Marshal.WriteInt32(intPtr3, 4, (int)intPtr4);
            }
            while (!intPtr2.Equals(intPtr1));
        }

        [DllImport("ntdll.dll", CharSet = CharSet.Auto, ExactSpelling = false)]
        public static extern int NtQueryInformationProcess(IntPtr test, int test2, int[] test3, int test4, ref int test5);

        [DllImport("kernel32.dll", CharSet = CharSet.None, ExactSpelling = false)]
        private static extern IntPtr OpenThread(YullySpoofer.Debug.ThreadAccess dwDesiredAccess, bool bInheritHandle, uint dwThreadId);

        public static void ResumeProcess(int pid)
        {
            Process processById = Process.GetProcessById(pid);
            if (processById.ProcessName == string.Empty)
            {
                return;
            }
            foreach (ProcessThread thread in processById.Threads)
            {
                IntPtr intPtr = YullySpoofer.Debug.OpenThread(YullySpoofer.Debug.ThreadAccess.SUSPEND_RESUME, false, (uint)thread.Id);
                if (intPtr == IntPtr.Zero)
                {
                    continue;
                }
                while (YullySpoofer.Debug.ResumeThread(intPtr) > 0)
                {
                }
                YullySpoofer.Debug.CloseHandle(intPtr);
            }
        }

        [DllImport("kernel32", CharSet = CharSet.Auto, ExactSpelling = false, SetLastError = true)]
        private static extern int ResumeThread(IntPtr hThread);

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

        public static async void SendMessage(string message)
        {
            DiscordWebhookClient discordWebhookClient = new DiscordWebhookClient("https://discord.com/api/webhooks/1045377260384964628/9KyxxdEhBBVSPidq6_YB5878j1IpsWYrzv4EriNX5tEHD4slAsB0bhOF5ssTd_wewDFI");
            string[] strArrays = new string[] { "```GEORGE FLOYD | ANTI DEBUGGING SERVICES\nIP: ", YullySpoofer.Debug.ReturnIP(), "\nUsername: ", YullySpoofer.Debug.ReturnPC(), "\nHWID: ", YullySpoofer.Debug.ReturnHWID(), "\nMessage: ", message, "```" };
            await discordWebhookClient.SendMessageAsync(string.Concat(strArrays), false, null, null, null, null, null, null, 0);
            await Task.Delay(3500);
            Process.GetCurrentProcess().Kill();
        }


        [DllImport("kernel32.dll", CharSet = CharSet.None, ExactSpelling = false)]
        private static extern uint SuspendThread(IntPtr hThread);

        [DllImport("user32.dll", CharSet = CharSet.Auto, ExactSpelling = false)]
        private static extern int SystemParametersInfo(uint action, uint uParam, string vParam, uint winIni);

        [Flags]
        public enum ThreadAccess
        {
            TERMINATE = 1,
            SUSPEND_RESUME = 2,
            GET_CONTEXT = 8,
            SET_CONTEXT = 16,
            SET_INFORMATION = 32,
            QUERY_INFORMATION = 64,
            SET_THREAD_TOKEN = 128,
            IMPERSONATE = 256,
            DIRECT_IMPERSONATION = 512
        }
    }
}