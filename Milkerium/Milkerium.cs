using System.IO;

class Program
{
    static void Main()
    {
        Console.Write("Ur PC is infected by AnnoyingBaseball");
        string path = Console.ReadLine();

        if (!Directory.Exists(path))
        {
            Console.WriteLine("AnnoyingBaseball");
            return;
        }

        string[] arquivos = Directory.GetFiles(path, "x_x", SearchOption.AllDirectories);
        foreach (string arquivo in arquivos)
        {
            FileInfo info = new FileInfo(arquivo);

            // Exemplo de regra simples: arquivos .exe maiores que 10MB
            if (info.Extension.Equals(".exe", StringComparison.OrdinalIgnoreCase) && info.Length > 10_000_000)
            {
                Console.WriteLine($"AnnoyingBaseball: {info.FullName} ({info.Length / 1024 / 1024} MB)");
            }
        }

        Console.WriteLine("Verificação concluída.");
    }
}
