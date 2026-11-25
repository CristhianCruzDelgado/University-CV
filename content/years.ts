import type { AcademicYear, Subject } from './types';

/** Subjects of every year, in the order the year columns show them. */
const fundamentalsOfComputerScience: Subject = {
  id: '111',
  name: 'Fundamentals Of Computer Science',
  description:
    'Basics of OS, programming, networks and databases. Linux environments and C++ programming paradigms.',
  projects: [
    {
      title:
        'Coursework on virtual machines, with GitHub, C++, CMake, Doxygen and VS Code',
      summary:
        'Bash commands and C++ exercises on Jutge, Exercism and other platforms. Google style guide.',
      directories: [{ path: 'assets/projects/fundamentals-cpp' }],
    },
  ],
};

const algebra: Subject = {
  id: '112',
  name: 'Algebra',
  description:
    'Propositional logic, sets and Boolean algebra, matrices and linear systems, vector spaces, diagonalization, Euclidean spaces, inner product and norm.',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const calculus: Subject = {
  id: '113',
  name: 'Calculus',
  description: 'Limits and continuity. Differentiability and integration.',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const physicalFoundationsOfEngineering: Subject = {
  id: '114',
  name: 'Physical Foundations of Engineering',
  description:
    'Classical and modern physics. Signal theory: direct and alternating current, electric and magnetic fields, and semiconductors.',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
    {
      title: 'Laboratory sessions in pairs',
      summary: 'Laboratory work: digital multimeter and oscilloscope.',
    },
  ],
};

const businessOrganization: Subject = {
  id: '115',
  name: 'Business Organization',
  description:
    'The firm and its environment. Finance, production and marketing.',
  projects: [
    {
      title: 'Group project',
      summary:
        'Aula Empresarial: a business model built from scratch, applying the theory of the subject.',
      files: [{ path: 'assets/projects/aula-empresarial.pdf' }],
    },
  ],
};

const algorithmsAndDataStructure: Subject = {
  id: '121',
  name: 'Algorithms and Data Structure',
  description:
    'Algorithms on vectors, matrices, singly and doubly linked lists, stacks and queues. Recursion.',
  projects: [
    {
      title: 'Coursework, with Visual Studio Code',
      summary: 'No content recorded.',
    },
  ],
};

const computerPrinciples: Subject = {
  id: '122',
  name: 'Computer Principles',
  description:
    'Number and character representation. Instructions, machine and assembly language. Von Neumann architecture: buses, memory, I/O, ALU and CU.',
  projects: [
    {
      title: 'Coursework, with QtSpim in MIPS32 assembly',
      summary: 'MIPS32 programs and subroutines.',
      directories: [{ path: 'assets/projects/fundamentals-assembly' }],
    },
  ],
};

const optimization: Subject = {
  id: '123',
  name: 'Optimization',
  description: 'Linear programming and graphs.',
  projects: [
    {
      title:
        'Coursework: combinatorics with WolframAlpha and linear programming with OR-Tools',
      summary: 'No content recorded.',
    },
    {
      title: 'Coursework: digital representation of graphs, with C++',
      summary:
        'Completion of C++ programs that solve graph problems: Kruskal and PDM.',
      directories: [{ path: 'assets/projects/graphs-cpp' }],
    },
  ],
};

const electronicAndDigitalSystems: Subject = {
  id: '124',
  name: 'Electronic and Digital Systems',
  description:
    'Logic gates, multiplexers and encoders. Combinational and sequential systems. Arithmetic circuits: addition and subtraction.',
  projects: [
    {
      title: 'Coursework: programs with Vivado in VHDL, on a Nexys A7 board',
      summary:
        'Simulation of logic functions and of a random counter, also run on a development board based on a Xilinx Artix-7 FPGA.',
      files: [
        { path: 'assets/projects/report-logic-functions.docx.pdf' },
        { path: 'assets/projects/report-random-counter.pdf' },
      ],
      directories: [{ path: 'assets/projects/simulations-vhdl' }],
    },
  ],
};

const engineeringGraphics: Subject = {
  id: '125',
  name: 'Engineering Graphics',
  description:
    'Technical drawing, standardization, orthographic views, sections, dimensioning and descriptive geometry (dihedral and dimensioned projection), covering project drawings, assemblies, part drawings, technical diagrams and CAD.',
  projects: [
    {
      title:
        'Coursework, with various applications: Fusion 360, Blender, Polycam and Revit',
      summary:
        'Introduction to 3D modelling, custom 3D design and graphics challenges.',
      files: [
        { path: 'assets/projects/report-point-clouds-3D-meshes.pdf' },
        { path: 'assets/projects/report-custom-3d-design.pdf' },
        { path: 'assets/projects/report-graphics-challenges.pdf' },
      ],
    },
    {
      title: 'Group project',
      summary: 'Virtual tour of an engineering project.',
      files: [
        {
          path: 'assets/projects/report-engineering-project-virtual-tour.pdf',
        },
      ],
    },
  ],
};

const statics: Subject = {
  id: '211',
  name: 'Statics',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const computabilityAndAlgorithmics: Subject = {
  id: '212',
  name: 'Computability and Algorithmics',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const computerStructure: Subject = {
  id: '213',
  name: 'Computer Structure',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const operatingSystems: Subject = {
  id: '214',
  name: 'Operating Systems',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const technicalEnglish: Subject = {
  id: '215',
  name: 'Technical English',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const advancedAlgorithmsAndDataStructure: Subject = {
  id: '221',
  name: 'Advanced Algorithms and Data Structure',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const networksAndDistributedSystems: Subject = {
  id: '222',
  name: 'Networks and Distributed Systems',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const systemsAdministration: Subject = {
  id: '223',
  name: 'Systems Administration',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const fundamentalsOfSoftwareEngineering: Subject = {
  id: '224',
  name: 'Fundamentals of Software Engineering',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const codeOfEthicsAndLegalAspects: Subject = {
  id: '225',
  name: 'Code of Ethics and Legal Aspects',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const databases: Subject = {
  id: '311',
  name: 'Databases',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const artificialIntelligence: Subject = {
  id: '312',
  name: 'Artificial Intelligence',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const humanComputerInteractionSystems: Subject = {
  id: '313',
  name: 'Human-Computer Interaction Systems',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const programmingLanguagesAndParadigms: Subject = {
  id: '314',
  name: 'Programming Languages and Paradigms',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const informaticProjectManagement: Subject = {
  id: '315',
  name: 'Informatic Project Management',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const languageProcessors: Subject = {
  id: '321',
  name: 'Language Processors',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const algorithmDesignAndAnalysis: Subject = {
  id: '322',
  name: 'Algorithm Design and Analysis',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const interactiveApplicationProgramming: Subject = {
  id: '323',
  name: 'Interactive Application Programming',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const advancedArtificialIntelligence: Subject = {
  id: '324',
  name: 'Advanced Artificial Intelligence',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const intelligentDataProcessing: Subject = {
  id: '325',
  name: 'Intelligent Data Processing',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const computerVision: Subject = {
  id: '411',
  name: 'Computer Vision',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const computationalRobotics: Subject = {
  id: '412',
  name: 'Computational Robotics',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const intelligentInterfaces: Subject = {
  id: '413',
  name: 'Intelligent Interfaces',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const intelligentSystems: Subject = {
  id: '414',
  name: 'Intelligent Systems',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const computationalComplexity: Subject = {
  id: '415',
  name: 'Computational Complexity',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const emotionalIntelligence: Subject = {
  id: '421',
  name: 'Emotial Intelligence',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const externalInternships: Subject = {
  id: '422',
  name: 'External Internships',
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

const bachelorsThesis: Subject = {
  id: '423',
  name: "Bachelor's Tesis",
  description: '',
  projects: [
    {
      title: 'Weekly assignments and exercises',
      summary: 'No content recorded.',
    },
  ],
};

/**
 * Single source of truth for the academic path. Ids appear in the URL, so
 * changing one changes the deep links that point to it.
 */
export const ACADEMIC_YEARS: readonly AcademicYear[] = [
  {
    id: '1',
    label: '1st Year (2023–2024)',
    semesters: [
      {
        id: '1',
        name: 'First Semester',
        subjects: [
          fundamentalsOfComputerScience,
          algebra,
          calculus,
          physicalFoundationsOfEngineering,
          businessOrganization,
        ],
      },
      {
        id: '2',
        name: 'Second Semester',
        subjects: [
          algorithmsAndDataStructure,
          computerPrinciples,
          optimization,
          electronicAndDigitalSystems,
          engineeringGraphics,
        ],
      },
    ],
  },
  {
    id: '2',
    label: '2nd Year (2024–2025)',
    semesters: [
      {
        id: '1',
        name: 'First Semester',
        subjects: [
          statics,
          computabilityAndAlgorithmics,
          computerStructure,
          operatingSystems,
          technicalEnglish,
        ],
      },
      {
        id: '2',
        name: 'Second Semester',
        subjects: [
          advancedAlgorithmsAndDataStructure,
          networksAndDistributedSystems,
          systemsAdministration,
          fundamentalsOfSoftwareEngineering,
          codeOfEthicsAndLegalAspects,
        ],
      },
    ],
  },
  {
    id: '3',
    label: '3rd Year (2025–2026)',
    semesters: [
      {
        id: '1',
        name: 'First Semester',
        subjects: [
          databases,
          artificialIntelligence,
          humanComputerInteractionSystems,
          programmingLanguagesAndParadigms,
          informaticProjectManagement,
        ],
      },
      {
        id: '2',
        name: 'Second Semester',
        subjects: [
          languageProcessors,
          algorithmDesignAndAnalysis,
          interactiveApplicationProgramming,
          advancedArtificialIntelligence,
          intelligentDataProcessing,
        ],
      },
    ],
  },
  {
    id: '4',
    label: '4th Year (2026–2027)',
    semesters: [
      {
        id: '1',
        name: 'First Semester',
        subjects: [
          computerVision,
          computationalRobotics,
          intelligentInterfaces,
          intelligentSystems,
          computationalComplexity,
        ],
      },
      {
        id: '2',
        name: 'Second Semester',
        subjects: [emotionalIntelligence, externalInternships, bachelorsThesis],
      },
    ],
  },
];
