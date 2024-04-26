using System;
using System.IO;
using System.Reflection;

class Virtualizer
{
    [System.Reflection.Obfuscation(Feature = "Virtualization", Exclude = false)]
    public void CreateFile(string filename, string content)
    {
        string directory = Path.GetDirectoryName(filename);
        if (!Directory.Exists(directory))
        {
            Directory.CreateDirectory(directory);
        }
        StreamWriter streamWriter = new StreamWriter(File.Open(filename, FileMode.OpenOrCreate, FileAccess.Write, FileShare.ReadWrite));
        streamWriter.Write(content);
        streamWriter.Flush();
        streamWriter.Close();
    }
}