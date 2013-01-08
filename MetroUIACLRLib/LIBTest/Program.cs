using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MetroUIACLRLib;
namespace LIBTest
{
    class Program
    {
        static void Main(string[] args)
        {
            MetroUIACLRLib.UIAutomation automatoin = null;
            
            if (!UIAutomation.CreateUIAutomation(out automatoin))
            {
                Console.WriteLine("CreateUIAutomation Failed");
                goto END;
            }
            
            UIAElement root = null;
            if (!automatoin.GetRootElement(out root))
            {
                Console.WriteLine("GetRootElement Failed");
                goto END;
            }

            System.String  automationId = System.String.Empty;
            if (!root.CurrentAutomationId(out automationId))
            {
                Console.WriteLine("CurrentAutomationId failed");
                goto END;
            }
            Console.WriteLine("CurrentAutomationId : {0}", automationId);

            if (!root.CurrentName(out automationId))
            {
                Console.WriteLine("CurrentName failed");
                goto END;
            }
            Console.WriteLine("CurrentName : {0}", automationId);

            int processId =0;
            if (!root.CurrentProcessId(out processId))
            {
                Console.WriteLine("CurrentProcessId failed");
                goto END;
            }

            Console.WriteLine("CurrentProcessId : {0}", processId);
            bool isOffScreen =false;
            if (!root.CurrentIsOffscreen(out isOffScreen))
            {
                Console.WriteLine("CurrentIsOffscreen failed");
                goto END;
            }
            Console.WriteLine("CurrentIsOffscreen : {0}", isOffScreen?"true":"false");

            if (!root.CurrentFrameworkId(out automationId))
            {
                Console.WriteLine("CurrentFrameworkId failed");
                goto END;
            }
            Console.WriteLine("CurrentFrameworkId : {0}", automationId);

            int cultureId = int.MinValue;
            if (!root.CurrentCulture(out cultureId))
            {
                Console.WriteLine("CurrentCulture failed");
                goto END;
            }

            Console.WriteLine("CurrentCulture : {0}", cultureId);

        END:
            Console.WriteLine("All over ...");
        Console.ReadLine();
        }
    }
}
